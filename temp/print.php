<head>
<meta http-equiv="Content-Type" content="text/html; charset=big5">
    <title> testing </title>
    <h1> test </h1>
    <body>
    <form method = "post">
        <input type = "submit" name = "test" id = "itest">
    </form>

    <?php
        header("Content-Type:text/html; charset=big5");
        function myPrint($str){
            $printer = "WP-K617 Ver.3.10";  
            $ph = printer_open($printer); 
            // $content = "print chinese use BIG5!";
            printer_write($ph, $str);
            printer_close($ph);
        }

        if(isset($_POST['test'])){
            // $file = "http://140.123.94.145/zhbot/myText.txt";
            // $file2 = "http://localhost/myText.txt";
            // $f = fopen($file,"r");
            // iconv("UTF-8","gbk//TRANSLIT",$f);
            // $str = "";
            // while(!feof($f)){
            //     $str .= fgets($f);
            // }
            $url='http://140.123.94.145/zhbot/myText.html';
            $html= file_get_contents($url);
            echo $html;
            // fclose($f);
            // myPrint($str);
            myPrint($html);
            
            // echo $str;
        }
    ?>
    </body>
</head>