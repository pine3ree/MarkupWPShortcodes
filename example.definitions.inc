<?php

$this->add('test', function ($atts, $content = null) {
    echo '<p>A TEST SHORTCODE</p>';
});

/**
 * Shortcode definition example using a static class
 */
class MyShortcodes
{
    /**
     * Create a BS3 row
     *
     * @param array $atts
     * @param string|null $content
     * @param MarkupWPShortcodes $parser
     * @return string|null
     */
    public static function row($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        if (empty($content)) return null;

        if (!$atts) $atts = array();

        $atts['class'] = isset($atts['class']) ? 'row ' . $atts['class'] : 'row';

        $attributes = array();
        foreach ($atts as $k => $v) {
            $attributes[] =  $k . '="' . $v . '"';
        }
        $attributes = implode(' ', $attributes);

        if ($parser) $content = $parser->render($content);

        $html = '<div class="row">' . $content . '</div>';

        return $html;
    }

    /**
     * Create a BS3 column to be nested in a row
     *
     * @param array $atts : w=width(1/2, 1/3, 2/3, 1/4, 1/6);
     * @param string|null $content
     * @param int|false $w
     * @param MarkupWPShortcodes $parser
     * @return string|null
     */
    public static function column($atts, $content = null, $w = false, MarkupWPShortcodes $parser = null)
    {
        if (empty($atts['w']) && !$w) return null;

        $width = $w ? $w : $atts['w'];

        $class = '';
        switch ($width) {
            case '12':	$class = 'col-sm-6'; break;

            case '13':	$class = 'col-sm-4'; break;
            case '23':	$class = 'col-sm-8'; break;

            case '14':	$class = 'col-sm-3'; break;
            case '34':	$class = 'col-sm-9'; break;

            case '16':	$class = 'col-sm-2'; break;

            default: return;
        }

        $default = array();

        /*** SET DEFAULTS ***/
        $default['title'] = null;
        $default['heading'] = 3;

        //override the defaults with the arguments supplied

        if (!$atts) $atts = array();
        $atts = array_merge($default, $atts);

        $atts['class'] = isset($atts['class']) ? $class . ' ' . $atts['class'] : $class;

        $h = $atts['heading'];
        $title = !empty($atts['title']) ? "<h$h>". $atts['title'] ."</h$h>" : '';

        $html = '<div class="' . $atts['class'] . '">' . $title . $content . '</div>';

        return $html;
    }

    public static function col12($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '12', $parser);
    }

    public static function col13($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '13', $parser);
    }
    public static function col23($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '23', $parser);
    }

    public static function col14($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '14', $parser);
    }
    public static function col34($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '34', $parser);
    }

    public static function col15($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '15', $parser);
    }
    public static function col25($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '25', $parser);
    }
    public static function col35($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '35', $parser);
    }
    public static function col45($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '45', $parser);
    }

    public static function col16($atts, $content = null, MarkupWPShortcodes $parser = null)
    {
        return self::column($atts, $content, '16', $parser);
    }
}

/**
 * Define the shortcodes in the parser
 */

// enable $parser to be caled inside shortcode callbacks
$parser = $this;

$this->add('col12', function ($atts, $content = null) use ($parser) {
    return MyShortcodes::col12($atts, $content, $parser);
});
$this->add('col13', function ($atts, $content = null) use ($parser) {
    return MyShortcodes::col13($atts, $content, $parser);
});
$this->add('col23', function ($atts, $content = null) use ($parser) {
    return MyShortcodes::col23($atts, $content, $parser);
});
$this->add('col14', function ($atts, $content = null) use ($parser) {
    return MyShortcodes::col14($atts, $content, $parser);
});
$this->add('col34', function ($atts, $content = null) use ($parser) {
    return MyShortcodes::col34($atts, $content, $parser);
});
$this->add('col16', function ($atts, $content = null) use ($parser) {
    return MyShortcodes::col16($atts, $content, $parser);
});
$this->add('row', function ($atts, $content = null) use ($parser) {
    return MyShortcodes::row($atts, $content, $parser);
});

/**
 * example in template files (usually you apply render to the body|main_content field)
 * <code>
 * echo $shortcodes->render('[row][col12]This is a 1/3 wide column[/col12][col23]This is a 2/3 wide column[/col23][/row]');
 * </code>
 */