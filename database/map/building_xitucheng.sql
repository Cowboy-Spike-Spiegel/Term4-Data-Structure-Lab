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
-- Table structure for table `建筑`
--

DROP TABLE IF EXISTS `建筑`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `建筑` (
  `name` varchar(45) NOT NULL,
  `出入口个数` int NOT NULL,
  `number1` int NOT NULL,
  `number2` int NOT NULL,
  `number3` int NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `建筑`
--

LOCK TABLES `建筑` WRITE;
/*!40000 ALTER TABLE `建筑` DISABLE KEYS */;
INSERT INTO `建筑` VALUES ('A区',1,32,0,0),('B区',1,31,0,0),('C区',1,30,0,0),('D1区',1,29,0,0),('D2区',2,21,24,0),('E区',2,22,23,0),('S2区',1,51,0,0),('S3区',1,54,0,0),('S4区',1,55,0,0),('S5区',2,56,57,0),('S6区',2,58,59,0),('东配楼',1,87,0,0),('信息楼S1',2,52,53,0),('医务室',1,76,0,0),('咖啡厅',1,88,0,0),('图书馆',2,84,86,0),('地下超市',1,33,0,0),('基建处',1,3,0,0),('学生活动中心',2,68,72,0),('学生食堂',3,64,65,66),('实验楼S2,S3',3,102,103,104),('小麦铺',1,70,0,0),('快递站',1,10,0,0),('报告厅',1,95,0,0),('教学实验综合楼N',2,94,97,0),('教学实验综合楼S',2,96,98,0),('教室楼S1',2,100,101,0),('教工食堂',3,60,61,69),('综合办公楼',1,68,0,0),('运动场',2,6,7,0),('邮局',1,71,0,0);
/*!40000 ALTER TABLE `建筑` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `本部建筑`
--

DROP TABLE IF EXISTS `本部建筑`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `本部建筑` (
  `name` varchar(45) NOT NULL,
  `出入口个数` int NOT NULL,
  `number1` int NOT NULL,
  `number2` int NOT NULL,
  `number3` int NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `本部建筑`
--

LOCK TABLES `本部建筑` WRITE;
/*!40000 ALTER TABLE `本部建筑` DISABLE KEYS */;
INSERT INTO `本部建筑` VALUES ('中门邮局',1,46,0,0),('主楼',2,34,35,0),('体育场',2,36,37,0),('体育馆',2,31,36,0),('停车坪',1,42,0,0),('创新楼',2,44,45,0),('北邮锦江酒店',2,4,57,0),('后勤处',1,58,0,0),('图书馆',3,17,27,20),('学一公寓',2,18,19,0),('学三公寓',2,15,16,0),('学九公寓',2,5,6,0),('学二公寓',2,19,20,0),('学二十九公寓',2,31,32,0),('学五公寓',2,12,13,0),('学八公寓',2,13,14,0),('学六公寓',1,23,0,0),('学十一公寓',2,3,4,0),('学十三公寓',1,15,0,0),('学十公寓',2,5,8,0),('学四公寓',2,16,17,0),('学生发展中心',3,14,17,27),('学生活动中心',2,8,11,0),('学生食堂',3,26,27,58),('学苑风味餐厅',2,26,27,0),('快递站',2,2,22,0),('招生办',1,2,0,0),('排球场网球场',2,27,30,0),('教一楼',2,34,35,0),('教三楼',2,39,42,0),('教九',2,4,5,0),('教二楼',3,38,39,43),('教四楼',3,18,20,34),('明光楼',2,49,55,0),('校医院',1,46,0,0),('校车车库',1,49,0,0),('档案馆',2,17,27,0),('浴室',2,11,26,0),('游泳馆',2,31,32,0),('物业中心配电室',1,30,0,0),('留学生公寓',2,5,6,0),('科学会堂',3,35,36,38),('科研楼',2,23,28,0),('篮球场',2,27,30,0),('经管楼',2,7,21,0),('综合服务楼',1,21,0,0),('综合食堂',2,5,8,0),('老干部活动中心',2,23,28,0),('行政办公楼',2,20,30,0),('财务处',1,20,0,0),('资产管理处审计处',1,20,0,0),('邮局',2,18,33,0),('青年公寓',1,9,0,0),('青年教师公寓',2,23,28,0),('鸿通楼',1,16,0,0);
/*!40000 ALTER TABLE `本部建筑` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-14 15:53:00
