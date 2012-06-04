<!DOCTYPE html>
 
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>

	<title><?php echo $feed->get_title(); ?></title>
	<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
	
	<link rel="stylesheet" href="<?php echo $theme_path ?>/style.css" type="text/css" media="all">

	<!-- Audio JS scripts -->
	<script src="inc/audiojs/jquery.js"></script>
	<script src="inc/audiojs/audio.min.js"></script>
	<script src="inc/audiojs/playlist.js"></script>
	
</head>
<body>
	
	<div class="audio"><audio preload></audio></div>
	<div id="wrapper">
 	
 			<div class="info">
		
				<?php if ($image = $feed->get_image_url()) { ?>
					<span class="image-wrap " style="width: auto; height: auto;"><img src="<?php echo $image;?>" class="feed-icon" alt="  " /></span>
				<?php } ?>

				<div class="feed-info">
 					<h1><a href="<?php echo $feed->get_permalink(); ?>"><?php echo $feed->get_title(); ?></a></h1>
 					
 					<p><?php echo $feed->get_description(); ?></p>
 					
 					<?php if ($author = $feed->get_author())
					{?>
						<p class="author">by <?php echo  $author->get_name();?></p>
					<?php } ?>
					
 		 		</div>		
 		
 				<ul class="subscribe">
 					<li class="feed-icon"><a href="<?php echo $feed->subscribe_url(); ?>">Podcast Feed</a></li>
 					<li class="itunes-icon"><a href="<?php echo $feed->subscribe_itunes(); ?>">Subscribe with iTunes</a></li>
 					<li class="google-icon"><a href="<?php echo $feed->subscribe_google(); ?>">Subscribe with Google Reader</a></li>
 				</ul>
 		
 				<div style="clear:both;"></div>
 		
 			</div><!--end info-->
 	
 		<ol>
			<?php
				
				/* Here, we'll loop through all of the items in the feed, and $item represents the current item in the loop.*/
	
				foreach ($feed->get_items() as $item): ?>
 				<?php if ($enclosure = $item->get_enclosure()) { ?>
 				
 					<li><a href="#" data-src="<?php echo $enclosure->get_link();?>"><strong><?php echo $item->get_title(); ?></strong> <?php echo $enclosure->get_duration(true);?></a>
				
				 <div class="description">
					 <?php echo $item->get_description(); ?>
				</div>
				 
				<p class="date"><?php echo $item->get_date("F j, Y"); ?></p>

				</li> 
			<?php	
					}; 
					endforeach; 
			?>
 		</ol>
 		
 		
 		<div class="footer">
 			<p><?php echo $feed->get_copyright(); ?></p>
 		</div>
 		
 	</div><!-- end wrapper -->
 	
</body>
</html>