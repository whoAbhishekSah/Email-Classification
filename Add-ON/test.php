<?php
$x = fopen('tmp.txt', 'w+');
fwrite($x, "hello world");
echo "<h1>hi there</h1>";
fclose($x);
?>