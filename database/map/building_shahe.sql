-- MySQL dump 10.13  Distrib 8.0.28, for Win64 (x86_64)
--
-- Host: localhost    Database: map
-- ------------------------------------------------------
-- Server version	8.0.28

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `shahebuilding`
--

DROP TABLE IF EXISTS `shahebuilding`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `shahebuilding` (
  `name` varchar(45) NOT NULL,
  `出入口个数` int NOT NULL,
  `number1` int NOT NULL,
  `number2` int NOT NULL,
  `number3` int NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shahebuilding`
--

LOCK TABLES `shahebuilding` WRITE;
/*!40000 ALTER TABLE `shahebuilding` DISABLE KEYS */;
INSERT INTO `shahebuilding` VALUES ('A区',1,32,0,0),('B区',1,31,0,0),('C区',1,30,0,0),('D1区',1,29,0,0),('D2区',2,21,24,0),('E区',2,22,23,0),('S2区',1,51,0,0),('S3区',1,54,0,0),('S4区',1,55,0,0),('S5区',2,56,57,0),('S6区',2,58,59,0),('东配楼',1,87,0,0),('信息楼S1',2,52,53,0),('医务室',1,76,0,0),('咖啡厅',1,88,0,0),('图书馆',2,84,86,0),('地下超市',1,33,0,0),('基建处',1,3,0,0),('学生活动中心',2,68,72,0),('学生食堂',3,64,65,66),('实验楼S2,S3',3,102,103,104),('小麦铺',1,70,0,0),('快递站',1,10,0,0),('报告厅',1,95,0,0),('教学实验综合楼N',2,94,97,0),('教学实验综合楼S',2,96,98,0),('教室楼S1',2,100,101,0),('教工食堂',3,60,61,69),('综合办公楼',1,68,0,0),('运动场',2,6,7,0),('邮局',1,71,0,0);
/*!40000 ALTER TABLE `shahebuilding` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-11 10:54:25
