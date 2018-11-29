<head>
<meta http-equiv="Content-Type" content="text/html; charset=big5">
    <title> testing </title>
    <h1> test </h1>
    <body>
    <script>
        <button onClick="window.print()">Print this page</button>
    </script>
    <form method = "post">
        <input type = "submit" name = "test" id = "itest">
    </form>
    <?php
        header("Content-Type:text/html; charset=big5");
        function myPrint($str){
            $printer = "WP-K617 Ver.3.10";  
            $ph = printer_open($printer); 
            // $content = "�n��BIG5�s�X!!";
            printer_write($ph, $str);
            printer_close($ph);
        }

        if(isset($_POST)){
            $file = "test.txt";
            $f = fopen($file,"r");
            $str = "";
            while(!feof($f)){
                $str .= fgets($f);
            }
            fclose($f);
            myPrint($str);
        }
    ?>
    </body>
</head>