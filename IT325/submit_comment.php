<html> <head> <title> output page </title></head> <body>
<?
$sid = $_REQUEST["sid"];
$sname = $_REQUEST["sname"];
$comment = $_REQUEST["comment"];
$sid = trim($sid);
$sname = trim($sname);
$comment = trim($comment);
$flag=0;

if($sid == ""){
 $flag =1;
 echo "Student ID is a required field. Please go back and fill out the Student ID.<br />";
}

if($sname == ""){
 $flag =1;
 echo "Student Name is a required field. Please go back and fill out the Student Name.<br />";
}

if($comment == ""){
 $flag =1;
 echo "Comment is a required field. Please go back and fill out the Comment.<br />";
}



// the user fills out all the fields
if($flag==0) {
		$data = "$sid, $sname, $comment \r\n";
                $file = "comment.txt";
                $fp = fopen($file, "w+") or die("Couldn't open $file for writing!");
                fwrite($fp, $data) or die("Couldn't write values to file!");
                fclose($fp);   //close the data file
                echo "Thank you for submitting the form!";
}
?>

</body>
</html>
