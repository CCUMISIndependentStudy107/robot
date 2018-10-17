<?php
// 資料庫連線
$server = ""; 
$user = "";
$password = "";
$db = "";
$conn = new mysqli($server, $user, $password, $db);
if ($conn->connect_error) {

    die("Connection failed: " . $conn->connect_error);

}
mysqli_query($conn, "SET NAMES UTF8");


// 傳輸
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    date_default_timezone_set("Asia/Taipei");

    $cardId = $_POST['cardId'];
    $price = $_POST['totalPrice'];
    $date = date("Y-m-d H:i:s");

    $stmt = $conn->prepare("INSERT INTO `record` (`card_id`, `price`, `date`) VALUES (?, ?, ?)");
    $stmt->bind_param('sis', $cardId, $price, $date);
    $stmt->execute();
    $stmt->close();
    echo "付款成功。";
}
else {
    echo "付款失敗。";
}

?>