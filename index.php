<?php
//Set path to theme folder
$theme_path = "themes/default";

// Get RSS file. This will break if there is more than one XML or RSS files in the directory.
$file = glob("./*.{xml,rss}", GLOB_BRACE);

// Concantonate the URL for feed
$file = "http://" . $_SERVER['HTTP_HOST']  . $_SERVER['REQUEST_URI'] . $file[0];
 
// Make sure SimplePie is included. You may need to change this to match the location of simplepie.inc.
require_once('inc/simplepie.inc');
 
// We'll process this feed with all of the default options.
$feed = new SimplePie();
 
// Set which feed to process.
$feed->set_feed_url($file);
 
// Run SimplePie.
$feed->init();
 
// This makes sure that the content is sent to the browser as text/html and the UTF-8 character set (since we didn't change it).
$feed->handle_content_type();

//Create theme path
$theme = $theme_path . "/theme.inc";
 
// Execute theme
require_once($theme);

?>