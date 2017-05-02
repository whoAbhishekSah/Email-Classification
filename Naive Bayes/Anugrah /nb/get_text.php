<?php
 $x = fopen('tmp.txt', 'w+');
 fwrite($x, "hello world");
//fclose($x);
if(isset($_POST['data'])) {
	$data = $_POST['data'];
	$f = fopen('test_file.txt', 'w+');
	fwrite($f, $data);
	fclose($f);
	$command = escapeshellcmd('python nb1.py');
	$output = shell_exec($command);
	fwrite($x, $output);
}
fclose($x);
?>