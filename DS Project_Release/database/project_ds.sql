/*
 Navicat Premium Data Transfer

 Source Server         : localhost
 Source Server Type    : MySQL
 Source Server Version : 80028
 Source Host           : localhost:3306
 Source Schema         : project_ds

 Target Server Type    : MySQL
 Target Server Version : 80028
 File Encoding         : 65001

 Date: 10/06/2022 15:10:35
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for 11_clock
-- ----------------------------
DROP TABLE IF EXISTS `11_clock`;
CREATE TABLE `11_clock`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 11_clock
-- ----------------------------

-- ----------------------------
-- Table structure for 11_clock_dayly
-- ----------------------------
DROP TABLE IF EXISTS `11_clock_dayly`;
CREATE TABLE `11_clock_dayly`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 11_clock_dayly
-- ----------------------------

-- ----------------------------
-- Table structure for 11_clock_weekly
-- ----------------------------
DROP TABLE IF EXISTS `11_clock_weekly`;
CREATE TABLE `11_clock_weekly`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `week` int NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 11_clock_weekly
-- ----------------------------

-- ----------------------------
-- Table structure for 11_once
-- ----------------------------
DROP TABLE IF EXISTS `11_once`;
CREATE TABLE `11_once`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `start_hour` int NOT NULL,
  `end_hour` int NOT NULL,
  `label` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 11_once
-- ----------------------------

-- ----------------------------
-- Table structure for 11_select
-- ----------------------------
DROP TABLE IF EXISTS `11_select`;
CREATE TABLE `11_select`  (
  `number` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `teacher` int NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `dayOfWeek` int NOT NULL,
  `c_index` int NOT NULL,
  `qun` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `extra` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 11_select
-- ----------------------------

-- ----------------------------
-- Table structure for 11_task
-- ----------------------------
DROP TABLE IF EXISTS `11_task`;
CREATE TABLE `11_task`  (
  `number` int NOT NULL,
  `lesson_number` int NOT NULL,
  `isSelect` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `hour` int NOT NULL,
  `isCommit` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 11_task
-- ----------------------------

-- ----------------------------
-- Table structure for 12_clock
-- ----------------------------
DROP TABLE IF EXISTS `12_clock`;
CREATE TABLE `12_clock`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 12_clock
-- ----------------------------

-- ----------------------------
-- Table structure for 12_clock_dayly
-- ----------------------------
DROP TABLE IF EXISTS `12_clock_dayly`;
CREATE TABLE `12_clock_dayly`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 12_clock_dayly
-- ----------------------------

-- ----------------------------
-- Table structure for 12_clock_weekly
-- ----------------------------
DROP TABLE IF EXISTS `12_clock_weekly`;
CREATE TABLE `12_clock_weekly`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `week` int NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 12_clock_weekly
-- ----------------------------

-- ----------------------------
-- Table structure for 12_once
-- ----------------------------
DROP TABLE IF EXISTS `12_once`;
CREATE TABLE `12_once`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `start_hour` int NOT NULL,
  `end_hour` int NOT NULL,
  `label` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 12_once
-- ----------------------------

-- ----------------------------
-- Table structure for 12_select
-- ----------------------------
DROP TABLE IF EXISTS `12_select`;
CREATE TABLE `12_select`  (
  `number` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `teacher` int NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `dayOfWeek` int NOT NULL,
  `c_index` int NOT NULL,
  `qun` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `extra` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 12_select
-- ----------------------------

-- ----------------------------
-- Table structure for 12_task
-- ----------------------------
DROP TABLE IF EXISTS `12_task`;
CREATE TABLE `12_task`  (
  `number` int NOT NULL,
  `lesson_number` int NOT NULL,
  `isSelect` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `hour` int NOT NULL,
  `isCommit` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 12_task
-- ----------------------------

-- ----------------------------
-- Table structure for 2_clock
-- ----------------------------
DROP TABLE IF EXISTS `2_clock`;
CREATE TABLE `2_clock`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `year` int NULL DEFAULT NULL,
  `month` int NULL DEFAULT NULL,
  `day` int NULL DEFAULT NULL,
  `hour` int NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 2_clock
-- ----------------------------
INSERT INTO `2_clock` VALUES ('test', 2022, 5, 1, 12);
INSERT INTO `2_clock` VALUES ('形式语言期末考试', 2022, 6, 22, 8);

-- ----------------------------
-- Table structure for 2_clock_dayly
-- ----------------------------
DROP TABLE IF EXISTS `2_clock_dayly`;
CREATE TABLE `2_clock_dayly`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 2_clock_dayly
-- ----------------------------
INSERT INTO `2_clock_dayly` VALUES ('8点', 8);
INSERT INTO `2_clock_dayly` VALUES ('10点睡觉', 22);

-- ----------------------------
-- Table structure for 2_clock_weekly
-- ----------------------------
DROP TABLE IF EXISTS `2_clock_weekly`;
CREATE TABLE `2_clock_weekly`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `week` int NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 2_clock_weekly
-- ----------------------------
INSERT INTO `2_clock_weekly` VALUES ('起床', 1, 7);
INSERT INTO `2_clock_weekly` VALUES ('周日中午打深渊', 7, 12);

-- ----------------------------
-- Table structure for 2_once
-- ----------------------------
DROP TABLE IF EXISTS `2_once`;
CREATE TABLE `2_once`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `start_hour` int NOT NULL,
  `end_hour` int NOT NULL,
  `label` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 2_once
-- ----------------------------
INSERT INTO `2_once` VALUES ('生日', 1, 6, 2022, 6, 18, 20, 21, NULL);
INSERT INTO `2_once` VALUES ('自习', 1, 16, 2022, 3, 21, 3, 6, '自习');
INSERT INTO `2_once` VALUES ('618抢货', 1, 27, 2022, 6, 18, 19, 20, '');
INSERT INTO `2_once` VALUES ('提交形势政策论文', 1, 16, 2022, 6, 7, 20, 22, '');
INSERT INTO `2_once` VALUES ('数据结构文档编写完毕', 1, 16, 2022, 6, 8, 20, 22, '');
INSERT INTO `2_once` VALUES ('自动机作业', 1, 16, 2022, 6, 8, 22, 23, '');
INSERT INTO `2_once` VALUES ('提交数据结构文档', 0, 9, 2022, 6, 10, 0, 0, '');
INSERT INTO `2_once` VALUES ('数据结构验收', 1, 25, 2022, 6, 15, 8, 9, '');
INSERT INTO `2_once` VALUES ('暑假踢球去', 0, 3, 2022, 6, 30, 18, 20, '锻炼');
INSERT INTO `2_once` VALUES ('旅游', 0, 7, 2022, 6, 28, 18, 20, '外出');

-- ----------------------------
-- Table structure for 2_select
-- ----------------------------
DROP TABLE IF EXISTS `2_select`;
CREATE TABLE `2_select`  (
  `number` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `teacher` int NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `dayOfWeek` int NOT NULL,
  `c_index` int NOT NULL,
  `qun` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `extra` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 2_select
-- ----------------------------
INSERT INTO `2_select` VALUES (2, '数据结构课程设计', 4, 1, 26, 1, 2, '2333333333', NULL);
INSERT INTO `2_select` VALUES (4, '数字逻辑课程设计', 9, 1, 25, 2, 4, '885114905', NULL);
INSERT INTO `2_select` VALUES (1, '数据结构课程设计', 4, 1, 25, 3, 2, '623128550', NULL);
INSERT INTO `2_select` VALUES (5, '数字逻辑课程设计', 9, 1, 26, 4, 4, '？', NULL);

-- ----------------------------
-- Table structure for 2_task
-- ----------------------------
DROP TABLE IF EXISTS `2_task`;
CREATE TABLE `2_task`  (
  `number` int NOT NULL,
  `lesson_number` int UNSIGNED NOT NULL,
  `isSelect` int UNSIGNED NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `hour` int NOT NULL,
  `isCommit` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 2_task
-- ----------------------------
INSERT INTO `2_task` VALUES (1, 1, 1, '课程设计验收', 2022, 6, 16, 9, 0);
INSERT INTO `2_task` VALUES (2, 1, 0, '网络层第一次作业', 2022, 5, 31, 23, 0);
INSERT INTO `2_task` VALUES (3, 2, 0, '网络层第二次作业', 2022, 6, 7, 23, 1);
INSERT INTO `2_task` VALUES (4, 2, 0, '网路层小测', 2022, 6, 10, 8, 1);
INSERT INTO `2_task` VALUES (5, 1, 1, '验收实验报告', 2022, 6, 20, 9, 0);
INSERT INTO `2_task` VALUES (6, 5, 0, '毛概期中视频作业', 2022, 5, 24, 18, 0);
INSERT INTO `2_task` VALUES (7, 5, 0, '毛概实践论文', 2022, 6, 12, 18, 0);
INSERT INTO `2_task` VALUES (8, 5, 0, '期末论文', 2022, 6, 26, 18, 0);

-- ----------------------------
-- Table structure for 3_clock
-- ----------------------------
DROP TABLE IF EXISTS `3_clock`;
CREATE TABLE `3_clock`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 3_clock
-- ----------------------------

-- ----------------------------
-- Table structure for 3_clock_dayly
-- ----------------------------
DROP TABLE IF EXISTS `3_clock_dayly`;
CREATE TABLE `3_clock_dayly`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 3_clock_dayly
-- ----------------------------

-- ----------------------------
-- Table structure for 3_clock_weekly
-- ----------------------------
DROP TABLE IF EXISTS `3_clock_weekly`;
CREATE TABLE `3_clock_weekly`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `week` int NOT NULL,
  `hour` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 3_clock_weekly
-- ----------------------------

-- ----------------------------
-- Table structure for 3_once
-- ----------------------------
DROP TABLE IF EXISTS `3_once`;
CREATE TABLE `3_once`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `start_hour` int NOT NULL,
  `end_hour` int NOT NULL,
  `label` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 3_once
-- ----------------------------

-- ----------------------------
-- Table structure for 3_select
-- ----------------------------
DROP TABLE IF EXISTS `3_select`;
CREATE TABLE `3_select`  (
  `number` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `teacher` int NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `dayOfWeek` int NOT NULL,
  `c_index` int NOT NULL,
  `qun` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `extra` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 3_select
-- ----------------------------

-- ----------------------------
-- Table structure for 3_task
-- ----------------------------
DROP TABLE IF EXISTS `3_task`;
CREATE TABLE `3_task`  (
  `number` int NOT NULL,
  `lesson_number` int NOT NULL,
  `isSelect` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `hour` int NOT NULL,
  `isCommit` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 3_task
-- ----------------------------
INSERT INTO `3_task` VALUES (2, 1, 0, '网络层第一次作业', 2022, 5, 31, 23, 0);
INSERT INTO `3_task` VALUES (3, 2, 0, '网络层第二次作业', 2022, 6, 7, 23, 0);
INSERT INTO `3_task` VALUES (4, 2, 0, '网路层小测', 2022, 6, 10, 8, 0);
INSERT INTO `3_task` VALUES (6, 5, 0, '毛概期中视频作业', 2022, 5, 24, 18, 0);
INSERT INTO `3_task` VALUES (7, 5, 0, '毛概实践论文', 2022, 6, 12, 18, 0);
INSERT INTO `3_task` VALUES (8, 5, 0, '期末论文', 2022, 6, 26, 18, 0);

-- ----------------------------
-- Table structure for acivity
-- ----------------------------
DROP TABLE IF EXISTS `acivity`;
CREATE TABLE `acivity`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `isShahe` int NOT NULL,
  `location` int NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `start_hour` int NOT NULL,
  `end_hour` int NOT NULL,
  `label` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `user` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of acivity
-- ----------------------------
INSERT INTO `acivity` VALUES ('计算机网络课程设计', 1, 25, 2022, 6, 26, 8, 9, '小组作业', 2);
INSERT INTO `acivity` VALUES ('提交毛概期末论文', 1, 25, 2022, 6, 26, 18, 20, '小组作业', 2);
INSERT INTO `acivity` VALUES ('期末考完啦', 1, 20, 2022, 6, 24, 6, 9, '聚餐', 2);
INSERT INTO `acivity` VALUES ('形式语言自动机实验二', 1, 27, 2022, 6, 17, 22, 23, '小组作业', 2);
INSERT INTO `acivity` VALUES ('1', 0, 1, 2024, 1, 1, 1, 1, '班会', 2);

-- ----------------------------
-- Table structure for building_shahe
-- ----------------------------
DROP TABLE IF EXISTS `building_shahe`;
CREATE TABLE `building_shahe`  (
  `name` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `出入口个数` int NOT NULL,
  `number1` int NOT NULL,
  `number2` int NOT NULL,
  `number3` int NOT NULL,
  PRIMARY KEY (`name`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of building_shahe
-- ----------------------------
INSERT INTO `building_shahe` VALUES ('A区', 1, 32, 0, 0);
INSERT INTO `building_shahe` VALUES ('B区', 1, 31, 0, 0);
INSERT INTO `building_shahe` VALUES ('C区', 1, 30, 0, 0);
INSERT INTO `building_shahe` VALUES ('D1区', 1, 29, 0, 0);
INSERT INTO `building_shahe` VALUES ('D2区', 2, 21, 24, 0);
INSERT INTO `building_shahe` VALUES ('E区', 2, 22, 23, 0);
INSERT INTO `building_shahe` VALUES ('S2区', 1, 51, 0, 0);
INSERT INTO `building_shahe` VALUES ('S3区', 1, 54, 0, 0);
INSERT INTO `building_shahe` VALUES ('S4区', 1, 55, 0, 0);
INSERT INTO `building_shahe` VALUES ('S5区', 2, 56, 57, 0);
INSERT INTO `building_shahe` VALUES ('S6区', 2, 58, 59, 0);
INSERT INTO `building_shahe` VALUES ('东配楼', 1, 87, 0, 0);
INSERT INTO `building_shahe` VALUES ('信息楼S1', 2, 52, 53, 0);
INSERT INTO `building_shahe` VALUES ('医务室', 1, 76, 0, 0);
INSERT INTO `building_shahe` VALUES ('咖啡厅', 1, 88, 0, 0);
INSERT INTO `building_shahe` VALUES ('图书馆', 2, 84, 86, 0);
INSERT INTO `building_shahe` VALUES ('地下超市', 1, 33, 0, 0);
INSERT INTO `building_shahe` VALUES ('基建处', 1, 3, 0, 0);
INSERT INTO `building_shahe` VALUES ('学生活动中心', 2, 68, 72, 0);
INSERT INTO `building_shahe` VALUES ('学生食堂', 3, 64, 65, 66);
INSERT INTO `building_shahe` VALUES ('实验楼S2,S3', 3, 102, 103, 104);
INSERT INTO `building_shahe` VALUES ('小麦铺', 1, 70, 0, 0);
INSERT INTO `building_shahe` VALUES ('快递站', 1, 10, 0, 0);
INSERT INTO `building_shahe` VALUES ('报告厅', 1, 95, 0, 0);
INSERT INTO `building_shahe` VALUES ('教学实验综合楼N', 2, 94, 97, 0);
INSERT INTO `building_shahe` VALUES ('教学实验综合楼S', 2, 96, 98, 0);
INSERT INTO `building_shahe` VALUES ('教室楼S1', 2, 100, 101, 0);
INSERT INTO `building_shahe` VALUES ('教工食堂', 3, 60, 61, 69);
INSERT INTO `building_shahe` VALUES ('综合办公楼', 1, 68, 0, 0);
INSERT INTO `building_shahe` VALUES ('运动场', 2, 6, 7, 0);
INSERT INTO `building_shahe` VALUES ('邮局', 1, 71, 0, 0);

-- ----------------------------
-- Table structure for building_xitucheng
-- ----------------------------
DROP TABLE IF EXISTS `building_xitucheng`;
CREATE TABLE `building_xitucheng`  (
  `name` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `出入口个数` int NOT NULL,
  `number1` int NOT NULL,
  `number2` int NOT NULL,
  `number3` int NOT NULL,
  PRIMARY KEY (`name`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of building_xitucheng
-- ----------------------------
INSERT INTO `building_xitucheng` VALUES ('中门邮局', 1, 46, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('主楼', 2, 34, 35, 0);
INSERT INTO `building_xitucheng` VALUES ('体育场', 2, 36, 37, 0);
INSERT INTO `building_xitucheng` VALUES ('体育馆', 2, 31, 36, 0);
INSERT INTO `building_xitucheng` VALUES ('停车坪', 1, 42, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('创新楼', 2, 44, 45, 0);
INSERT INTO `building_xitucheng` VALUES ('北邮锦江酒店', 2, 4, 57, 0);
INSERT INTO `building_xitucheng` VALUES ('后勤处', 1, 58, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('图书馆', 3, 17, 27, 20);
INSERT INTO `building_xitucheng` VALUES ('学一公寓', 2, 18, 19, 0);
INSERT INTO `building_xitucheng` VALUES ('学三公寓', 2, 15, 16, 0);
INSERT INTO `building_xitucheng` VALUES ('学九公寓', 2, 5, 6, 0);
INSERT INTO `building_xitucheng` VALUES ('学二公寓', 2, 19, 20, 0);
INSERT INTO `building_xitucheng` VALUES ('学二十九公寓', 2, 31, 32, 0);
INSERT INTO `building_xitucheng` VALUES ('学五公寓', 2, 12, 13, 0);
INSERT INTO `building_xitucheng` VALUES ('学八公寓', 2, 13, 14, 0);
INSERT INTO `building_xitucheng` VALUES ('学六公寓', 1, 23, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('学十一公寓', 2, 3, 4, 0);
INSERT INTO `building_xitucheng` VALUES ('学十三公寓', 1, 15, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('学十公寓', 2, 5, 8, 0);
INSERT INTO `building_xitucheng` VALUES ('学四公寓', 2, 16, 17, 0);
INSERT INTO `building_xitucheng` VALUES ('学生发展中心', 3, 14, 17, 27);
INSERT INTO `building_xitucheng` VALUES ('学生活动中心', 2, 8, 11, 0);
INSERT INTO `building_xitucheng` VALUES ('学生食堂', 3, 26, 27, 58);
INSERT INTO `building_xitucheng` VALUES ('学苑风味餐厅', 2, 26, 27, 0);
INSERT INTO `building_xitucheng` VALUES ('快递站', 2, 2, 22, 0);
INSERT INTO `building_xitucheng` VALUES ('招生办', 1, 2, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('排球场网球场', 2, 27, 30, 0);
INSERT INTO `building_xitucheng` VALUES ('教一楼', 2, 34, 35, 0);
INSERT INTO `building_xitucheng` VALUES ('教三楼', 2, 39, 42, 0);
INSERT INTO `building_xitucheng` VALUES ('教九', 2, 4, 5, 0);
INSERT INTO `building_xitucheng` VALUES ('教二楼', 3, 38, 39, 43);
INSERT INTO `building_xitucheng` VALUES ('教四楼', 3, 18, 20, 34);
INSERT INTO `building_xitucheng` VALUES ('明光楼', 2, 49, 55, 0);
INSERT INTO `building_xitucheng` VALUES ('校医院', 1, 46, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('校车车库', 1, 49, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('档案馆', 2, 17, 27, 0);
INSERT INTO `building_xitucheng` VALUES ('浴室', 2, 11, 26, 0);
INSERT INTO `building_xitucheng` VALUES ('游泳馆', 2, 31, 32, 0);
INSERT INTO `building_xitucheng` VALUES ('物业中心配电室', 1, 30, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('留学生公寓', 2, 5, 6, 0);
INSERT INTO `building_xitucheng` VALUES ('科学会堂', 3, 35, 36, 38);
INSERT INTO `building_xitucheng` VALUES ('科研楼', 2, 23, 28, 0);
INSERT INTO `building_xitucheng` VALUES ('篮球场', 2, 27, 30, 0);
INSERT INTO `building_xitucheng` VALUES ('经管楼', 2, 7, 21, 0);
INSERT INTO `building_xitucheng` VALUES ('综合服务楼', 1, 21, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('综合食堂', 2, 5, 8, 0);
INSERT INTO `building_xitucheng` VALUES ('老干部活动中心', 2, 23, 28, 0);
INSERT INTO `building_xitucheng` VALUES ('行政办公楼', 2, 20, 30, 0);
INSERT INTO `building_xitucheng` VALUES ('财务处', 1, 20, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('资产管理处审计处', 1, 20, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('邮局', 2, 18, 33, 0);
INSERT INTO `building_xitucheng` VALUES ('青年公寓', 1, 9, 0, 0);
INSERT INTO `building_xitucheng` VALUES ('青年教师公寓', 2, 23, 28, 0);
INSERT INTO `building_xitucheng` VALUES ('鸿通楼', 1, 16, 0, 0);

-- ----------------------------
-- Table structure for lesson_compulsory
-- ----------------------------
DROP TABLE IF EXISTS `lesson_compulsory`;
CREATE TABLE `lesson_compulsory`  (
  `number` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `teacher` int NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `dayOfWeek` int NOT NULL,
  `c_index` int NOT NULL,
  `qun` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `extra` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `class` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lesson_compulsory
-- ----------------------------
INSERT INTO `lesson_compulsory` VALUES (1, '计算机网络', 5, 1, 25, 2, 2, '微信群', '403', '2020211305');
INSERT INTO `lesson_compulsory` VALUES (2, '计算机网络', 5, 1, 25, 4, 2, '微信群', '403', '2020211305');
INSERT INTO `lesson_compulsory` VALUES (3, '计算机组成原理', 6, 1, 25, 1, 3, '微信群', '203', '2020211305');
INSERT INTO `lesson_compulsory` VALUES (4, '形式语言与自动机', 7, 1, 25, 1, 1, '915278157', '201', '2020211305');
INSERT INTO `lesson_compulsory` VALUES (5, '毛概', 10, 1, 25, 4, 1, '601810251', '215', '2020211305');
INSERT INTO `lesson_compulsory` VALUES (6, '毛概', 10, 1, 25, 2, 1, '？', '215', '2020211304');
INSERT INTO `lesson_compulsory` VALUES (7, '数据结构', 4, 0, 3, 7, 3, '2333', '310', '');
INSERT INTO `lesson_compulsory` VALUES (8, '数据结构补充课程', 4, 1, 21, 7, 2, '无', '310', '2020211305');
INSERT INTO `lesson_compulsory` VALUES (9, '数据结构习题讲解', 4, 1, 25, 6, 3, '无', '310', '2020211305');

-- ----------------------------
-- Table structure for lesson_select
-- ----------------------------
DROP TABLE IF EXISTS `lesson_select`;
CREATE TABLE `lesson_select`  (
  `number` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `teacher` int NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `dayOfWeek` int NOT NULL,
  `c_index` int NOT NULL,
  `qun` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `extra` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lesson_select
-- ----------------------------
INSERT INTO `lesson_select` VALUES (1, '数据结构课程设计', 4, 1, 25, 3, 2, '623128550', '201');
INSERT INTO `lesson_select` VALUES (2, '数据结构课程设计', 4, 1, 26, 1, 2, '2333333333', '201');
INSERT INTO `lesson_select` VALUES (3, 'C++', 8, 1, 25, 5, 2, '906461954', '205');
INSERT INTO `lesson_select` VALUES (4, '数字逻辑课程设计', 9, 1, 25, 2, 4, '885114905', '204');
INSERT INTO `lesson_select` VALUES (5, '数字逻辑课程设计', 9, 1, 26, 4, 4, '？', '204');
INSERT INTO `lesson_select` VALUES (6, '数据结构讲解课程', 4, 1, 0, 5, 4, '无', '205');

-- ----------------------------
-- Table structure for lesson_task
-- ----------------------------
DROP TABLE IF EXISTS `lesson_task`;
CREATE TABLE `lesson_task`  (
  `number` int NOT NULL,
  `lesson_number` int NOT NULL,
  `isSelect` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `hour` int NOT NULL,
  `all_number` int NOT NULL,
  `commit_number` int NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lesson_task
-- ----------------------------
INSERT INTO `lesson_task` VALUES (1, 1, 1, '课程设计验收', 2022, 6, 16, 9, 1, 0);
INSERT INTO `lesson_task` VALUES (2, 1, 0, '网络层第一次作业', 2022, 5, 31, 23, 3, 0);
INSERT INTO `lesson_task` VALUES (3, 2, 0, '网络层第二次作业', 2022, 6, 7, 23, 3, 1);
INSERT INTO `lesson_task` VALUES (4, 2, 0, '网路层小测', 2022, 6, 10, 8, 3, 1);
INSERT INTO `lesson_task` VALUES (5, 1, 1, '验收实验报告', 2022, 6, 20, 9, 1, 0);
INSERT INTO `lesson_task` VALUES (6, 5, 0, '毛概期中视频作业', 2022, 5, 24, 18, 3, 0);
INSERT INTO `lesson_task` VALUES (7, 5, 0, '毛概实践论文', 2022, 6, 12, 18, 3, 0);
INSERT INTO `lesson_task` VALUES (8, 5, 0, '期末论文', 2022, 6, 26, 18, 3, 0);

-- ----------------------------
-- Table structure for lesson_test
-- ----------------------------
DROP TABLE IF EXISTS `lesson_test`;
CREATE TABLE `lesson_test`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `lesson_number` int NOT NULL,
  `isSelect` int NOT NULL,
  `isShaHe` int NOT NULL,
  `location` int NOT NULL,
  `year` int NOT NULL,
  `month` int NOT NULL,
  `day` int NOT NULL,
  `time` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `extra` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lesson_test
-- ----------------------------
INSERT INTO `lesson_test` VALUES ('验收', 1, 1, 1, 26, 2022, 6, 16, '09:00:00', NULL);
INSERT INTO `lesson_test` VALUES ('期末没有考试，论文形式', 5, 0, 0, 55, 2022, 6, 28, '18:00:00', '二楼xxx');

-- ----------------------------
-- Table structure for map_shahe
-- ----------------------------
DROP TABLE IF EXISTS `map_shahe`;
CREATE TABLE `map_shahe`  (
  `number` int NOT NULL,
  `isShaHe` tinyint NOT NULL,
  `abscissa` double NOT NULL,
  `ordinate` double NOT NULL,
  `number_1` int NOT NULL,
  `road_1.forWalk` int NOT NULL,
  `road_1.diatance` double NOT NULL,
  `road_1.crowd` double NOT NULL,
  `number_2` int NOT NULL,
  `road_2.forWalk` int NOT NULL,
  `road_2.diatance` double NOT NULL,
  `road_2.crowd` double NOT NULL,
  `number_3` int NOT NULL,
  `road_3.forWalk` int NOT NULL,
  `road_3.diatance` double NOT NULL,
  `road_3.crowd` double NOT NULL,
  `number_4` int UNSIGNED NOT NULL,
  `road_4.forWalk` int NOT NULL,
  `road_4.diatance` double NOT NULL,
  `road_4.crowd` double NOT NULL,
  PRIMARY KEY (`number`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of map_shahe
-- ----------------------------
INSERT INTO `map_shahe` VALUES (1, 1, 0, 390, 0, -1, 0, 0, 3, 0, 36, 1, 0, -1, 0, 0, 0, 0, 0, 0.76);
INSERT INTO `map_shahe` VALUES (2, 1, 637, 0, 96, 0, 139.5, 0.91, 129, 0, 436.8, 0.43, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (3, 1, 36, 390, 10, 0, 32, 0.23, 4, 0, 60.6, 1, 0, -1, 0, 0, 1, 0, 36, 1);
INSERT INTO `map_shahe` VALUES (4, 1, 96.6, 390, 0, -1, 0, 0, 5, 0, 182, 1, 0, -1, 0, 0, 3, 0, 60.6, 1);
INSERT INTO `map_shahe` VALUES (5, 1, 278.6, 390, 6, 0, 74, 0.87, 28, 0, 93.5, 1, 14, 0, 64.5, 0.87, 4, 0, 182, 1);
INSERT INTO `map_shahe` VALUES (6, 1, 278.6, 464, 20, 0, 74.1, 0.87, 32, 1, 22.6, 0.56, 5, 0, 74, 0.87, 13, 1, 58, 0.94);
INSERT INTO `map_shahe` VALUES (7, 1, 278.6, 592.9, 8, 0, 41.9, 0.87, 23, 1, 38.7, 0.87, 20, 0, 54.8, 0.87, 11, 1, 58, 0.94);
INSERT INTO `map_shahe` VALUES (8, 1, 278.6, 634.8, 16, 0, 100, 0.72, 22, 1, 48.3, 0.87, 7, 0, 41.9, 0.87, 11, 1, 70.9, 0.94);
INSERT INTO `map_shahe` VALUES (9, 1, 0, 422, 0, -1, 0, 0, 10, 1, 36, 0.17, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (10, 1, 36, 422, 0, -1, 0, 0, 0, -1, 0, 0, 3, 0, 32, 0.23, 9, 1, 36, 0.17);
INSERT INTO `map_shahe` VALUES (11, 1, 220.6, 592.9, 8, 1, 70.9, 0.94, 7, 1, 58, 0.94, 12, 1, 54.8, 0.94, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (12, 1, 220.6, 538.1, 11, 1, 54.8, 0.94, 0, -1, 0, 0, 13, 1, 74.1, 0.94, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (13, 1, 220.6, 464, 12, 1, 74.1, 0.94, 6, 1, 58, 0.94, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (14, 1, 278.6, 325.5, 5, 0, 64.5, 0.87, 52, 1, 64.5, 0.72, 53, 1, 48.3, 0.56, 15, 0, 325.5, 0.87);
INSERT INTO `map_shahe` VALUES (15, 1, 390, 0, 14, 0, 325.5, 0.87, 41, 0, 154.7, 0.96, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (16, 1, 378.6, 654.3, 0, -1, 0, 0, 17, 0, 48.3, 0.72, 21, 0, 19.3, 0.42, 8, 0, 100, 0.72);
INSERT INTO `map_shahe` VALUES (17, 1, 426.9, 654.3, 0, -1, 0, 0, 61, 0, 67.7, 0.7, 18, 0, 141.8, 0.56, 16, 0, 48.3, 0.72);
INSERT INTO `map_shahe` VALUES (18, 1, 426.9, 538.1, 17, 0, 141.8, 0.56, 60, 0, 67.7, 0.45, 64, 0, 26.2, 0.56, 30, 0, 36.3, 0.45);
INSERT INTO `map_shahe` VALUES (19, 1, 323.7, 538.1, 0, -1, 0, 0, 30, 0, 53.9, 0.45, 31, 0, 16.1, 0.39, 20, 0, 45.1, 0.45);
INSERT INTO `map_shahe` VALUES (20, 1, 278.6, 538.1, 7, 0, 54.8, 0.87, 23, 1, 58.6, 0.23, 19, 0, 45.1, 0.45, 6, 0, 74.1, 0.87);
INSERT INTO `map_shahe` VALUES (21, 1, 378.6, 635, 16, 0, 19.3, 0.42, 24, 1, 44.5, 0.33, 25, 1, 58.6, 0.33, 23, 1, 82.8, 0.33);
INSERT INTO `map_shahe` VALUES (22, 1, 309.2, 613.2, 0, -1, 0, 0, 0, -1, 0, 0, 23, 1, 30.3, 0.33, 8, 1, 48.3, 0.87);
INSERT INTO `map_shahe` VALUES (23, 1, 317.3, 591.9, 22, 1, 30.3, 0.33, 21, 1, 82.8, 0.33, 20, 1, 58.6, 0.23, 7, 1, 38.7, 0.87);
INSERT INTO `map_shahe` VALUES (24, 1, 389.1, 583.4, 21, 1, 44.5, 0.33, 0, -1, 0, 0, 25, 1, 18.2, 0.33, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (25, 1, 370.4, 561.5, 21, 1, 58.6, 0.33, 24, 1, 18.2, 0.33, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (26, 1, 426.9, 469.5, 64, 0, 26.2, 0.56, 65, 0, 54.6, 0.56, 0, -1, 0, 0, 35, 0, 40.4, 0.21);
INSERT INTO `map_shahe` VALUES (27, 1, 416.6, 390, 65, 0, 60.6, 0.56, 67, 0, 115.2, 1, 38, 0, 88.9, 0.47, 28, 0, 44.5, 1);
INSERT INTO `map_shahe` VALUES (28, 1, 372.1, 390, 29, 0, 48.5, 0.21, 27, 0, 44.5, 1, 0, -1, 0, 0, 5, 0, 93.5, 1);
INSERT INTO `map_shahe` VALUES (29, 1, 372.1, 438.5, 34, 0, 20.2, 0.21, 0, -1, 0, 0, 28, 0, 48.5, 0.21, 33, 1, 30.3, 0.21);
INSERT INTO `map_shahe` VALUES (30, 1, 377.4, 538.1, 0, -1, 0, 0, 18, 0, 36.3, 0.45, 0, -1, 0, 0, 19, 0, 53.9, 0.45);
INSERT INTO `map_shahe` VALUES (31, 1, 323.7, 522, 19, 0, 16.1, 0.39, 0, -1, 0, 0, 36, 0, 20.2, 0.39, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (32, 1, 301.2, 464, 0, -1, 0, 0, 37, 0, 20.2, 0.56, 0, -1, 0, 0, 6, 1, 22.6, 0.56);
INSERT INTO `map_shahe` VALUES (33, 1, 343.8, 438.5, 34, 1, 30.3, 0.21, 29, 1, 28.3, 0.21, 0, -1, 0, 0, 37, 1, 30.3, 0.21);
INSERT INTO `map_shahe` VALUES (34, 1, 372.1, 458.7, 35, 1, 36.3, 0.21, 29, 0, 20.2, 0.21, 33, 1, 30.3, 0.21, 37, 1, 46.5, 0.21);
INSERT INTO `map_shahe` VALUES (35, 1, 372.1, 495, 0, -1, 0, 0, 26, 0, 40.4, 0.21, 34, 1, 36.3, 0.21, 36, 1, 46.5, 0.21);
INSERT INTO `map_shahe` VALUES (36, 1, 325.6, 495, 31, 0, 20.2, 0.39, 35, 1, 46.5, 0.21, 37, 1, 26.3, 0.21, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (37, 1, 325.6, 458.7, 36, 0, 36.3, 0.21, 34, 1, 46.5, 0.21, 33, 1, 30.3, 0.21, 32, 0, 20.2, 0.56);
INSERT INTO `map_shahe` VALUES (38, 1, 416.6, 301.1, 27, 0, 88.9, 0.47, 77, 0, 107.1, 0.47, 54, 1, 70.7, 0.34, 51, 0, 38.4, 0.22);
INSERT INTO `map_shahe` VALUES (39, 1, 416.6, 147.5, 77, 0, 46.5, 0.47, 79, 0, 32.3, 0.47, 56, 0, 26.3, 0.28, 55, 1, 52.5, 0.47);
INSERT INTO `map_shahe` VALUES (40, 1, 416.6, 74.8, 79, 0, 40.4, 0.47, 0, -1, 0, 0, 41, 0, 84.9, 0.47, 42, 0, 48.5, 0.28);
INSERT INTO `map_shahe` VALUES (41, 1, 416.6, 0, 40, 0, 84.9, 0.47, 83, 0, 76.7, 0.83, 0, -1, 0, 0, 15, 0, 154.7, 0.96);
INSERT INTO `map_shahe` VALUES (42, 1, 368.1, 74.8, 57, 1, 24.2, 0.28, 40, 1, 48.5, 0.28, 59, 1, 40.4, 0.28, 43, 1, 44.5, 0.28);
INSERT INTO `map_shahe` VALUES (43, 1, 337.8, 105.1, 0, -1, 0, 0, 42, 1, 44.5, 0.28, 58, 1, 40.4, 0.28, 44, 1, 58.6, 0.28);
INSERT INTO `map_shahe` VALUES (44, 1, 279.2, 105.1, 45, 1, 70.7, 0.22, 43, 1, 58.6, 0.28, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (45, 1, 279.2, 175.8, 47, 1, 42.4, 0.22, 46, 1, 60.6, 0.28, 44, 1, 70.7, 0.22, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (46, 1, 339.8, 175.8, 0, -1, 0, 0, 56, 1, 54.6, 0.28, 0, -1, 0, 0, 45, 1, 60.6, 0.28);
INSERT INTO `map_shahe` VALUES (47, 1, 366, 214.2, 49, 1, 64.7, 0.22, 48, 1, 34.3, 0.34, 45, 1, 42.4, 0.22, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (48, 1, 400.4, 214.2, 0, -1, 0, 0, 52, 1, 36.4, 0.34, 0, -1, 0, 0, 47, 1, 34.4, 0.34);
INSERT INTO `map_shahe` VALUES (49, 1, 400.4, 278.9, 50, 1, 36.4, 0.22, 0, -1, 0, 0, 47, 1, 64.7, 0.22, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (50, 1, 426.9, 301.1, 0, -1, 0, 0, 51, 1, 30.3, 0.22, 0, -1, 0, 0, 49, 1, 36.4, 0.22);
INSERT INTO `map_shahe` VALUES (51, 1, 380.2, 301.1, 0, -1, 0, 0, 38, 0, 38.4, 0.22, 0, -1, 0, 0, 50, 1, 30.3, 0.22);
INSERT INTO `map_shahe` VALUES (52, 1, 343.1, 325.5, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 14, 1, 64.5, 0.72);
INSERT INTO `map_shahe` VALUES (53, 1, 320.9, 311.4, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 14, 1, 48.3, 0.87);
INSERT INTO `map_shahe` VALUES (54, 1, 380.2, 238.5, 0, -1, 0, 0, 38, 1, 70.7, 0.34, 0, -1, 0, 0, 48, 1, 36.4, 0.34);
INSERT INTO `map_shahe` VALUES (55, 1, 404.4, 194, 0, -1, 0, 0, 77, 0, 30.3, 0.47, 39, 0, 52.5, 0.47, 56, 1, 54.6, 0.28);
INSERT INTO `map_shahe` VALUES (56, 1, 399.1, 147.5, 55, 1, 54.6, 0.28, 39, 0, 26.3, 0.47, 0, -1, 0, 0, 46, 1, 54.6, 0.28);
INSERT INTO `map_shahe` VALUES (57, 1, 399.1, 107.1, 0, -1, 0, 0, 79, 0, 40.4, 0.47, 42, 1, 24.2, 0.28, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (58, 1, 337.8, 64.7, 43, 1, 40.4, 0.28, 0, -1, 0, 0, 59, 1, 44.5, 0.28, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (59, 1, 399.1, 48.5, 42, 1, 40.4, 0.28, 0, -1, 0, 0, 0, -1, 0, 0, 58, 1, 44.5, 0.28);
INSERT INTO `map_shahe` VALUES (60, 1, 494.6, 538.1, 0, -1, 0, 0, 63, 0, 51.6, 0.45, 0, -1, 0, 0, 18, 0, 67.7, 0.45);
INSERT INTO `map_shahe` VALUES (61, 1, 494.6, 643.1, 0, -1, 0, 0, 62, 0, 51.6, 0.76, 0, -1, 0, 0, 17, 1, 67.7, 0.76);
INSERT INTO `map_shahe` VALUES (62, 1, 546.2, 643.1, 0, -1, 0, 0, 75, 0, 84.9, 0.76, 69, 0, 50.5, 0.37, 61, 0, 51.6, 0.76);
INSERT INTO `map_shahe` VALUES (63, 1, 546.2, 538.1, 69, 0, 44.4, 0.37, 68, 0, 70.7, 0.45, 66, 0, 20.2, 0.37, 60, 0, 51.6, 0.45);
INSERT INTO `map_shahe` VALUES (64, 1, 430.1, 472.3, 18, 0, 42.4, 0.56, 0, -1, 0, 0, 0, -1, 0, 0, 26, 0, 26.2, 0.56);
INSERT INTO `map_shahe` VALUES (65, 1, 442.9, 442.5, 26, 0, 54.6, 0.56, 0, -1, 0, 0, 27, 0, 60.6, 0.56, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (66, 1, 546.2, 472.3, 63, 0, 20.2, 0.37, 70, 1, 20.2, 0.56, 105, 0, 60.6, 0.56, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (67, 1, 546.2, 390, 105, 0, 50.5, 0.37, 73, 0, 123.3, 1, 0, -1, 0, 0, 27, 0, 115.2, 1);
INSERT INTO `map_shahe` VALUES (68, 1, 616.9, 538.1, 0, -1, 0, 0, 74, 0, 14.9, 0.45, 72, 1, 90.9, 0.14, 63, 0, 70.7, 0.45);
INSERT INTO `map_shahe` VALUES (69, 1, 546.2, 592.6, 62, 0, 50.5, 0.37, 0, -1, 0, 0, 63, 0, 44.4, 0.37, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (70, 1, 550.4, 461.5, 0, -1, 0, 0, 0, -1, 0, 0, 66, 0, 20.2, 0.37, 105, 0, 52.5, 0.37);
INSERT INTO `map_shahe` VALUES (71, 1, 606.8, 442.5, 0, -1, 0, 0, 72, 1, 34.3, 0.14, 0, -1, 0, 0, 105, 1, 60.6, 0.14);
INSERT INTO `map_shahe` VALUES (72, 1, 641.1, 442.5, 68, 1, 90.9, 0.14, 84, 1, 115.2, 0.14, 0, -1, 0, 0, 71, 1, 34.3, 0.14);
INSERT INTO `map_shahe` VALUES (73, 1, 669.5, 390, 74, 0, 143.5, 0.96, 84, 1, 80.8, 0.96, 94, 0, 60.6, 0.43, 67, 0, 123.3, 1);
INSERT INTO `map_shahe` VALUES (74, 1, 631.1, 538.1, 75, 0, 105.1, 0.96, 86, 1, 101, 0.89, 73, 0, 143.5, 0.96, 68, 0, 14.9, 0.45);
INSERT INTO `map_shahe` VALUES (75, 1, 631.1, 643.1, 76, 1, 46.5, 0.83, 0, -1, 0, 0, 74, 0, 105.1, 0.96, 62, 0, 84.9, 0.76);
INSERT INTO `map_shahe` VALUES (76, 1, 620.4, 656.2, 0, -1, 0, 0, 75, 1, 46.5, 0.83, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (77, 1, 416.6, 195.2, 38, 0, 107.1, 0.47, 78, 0, 138.4, 0.83, 39, 0, 46.5, 0.47, 55, 0, 30.3, 0.47);
INSERT INTO `map_shahe` VALUES (78, 1, 655, 195.2, 96, 1, 50.5, 0.43, 91, 0, 238.4, 0.83, 81, 0, 86.9, 0.83, 77, 0, 238.4, 0.83);
INSERT INTO `map_shahe` VALUES (79, 1, 416.6, 108.3, 39, 0, 32.3, 0.47, 80, 0, 149.5, 0.83, 40, 0, 40.4, 0.47, 57, 0, 40.4, 0.47);
INSERT INTO `map_shahe` VALUES (80, 1, 566.1, 108.3, 0, -1, 0, 0, 81, 0, 88.9, 0.83, 82, 0, 90.9, 0.83, 79, 0, 149.5, 0.83);
INSERT INTO `map_shahe` VALUES (81, 1, 655, 108.3, 78, 0, 86.9, 0.83, 92, 0, 238.4, 0.83, 2, 0, 108.3, 0.83, 80, 0, 88.9, 0.83);
INSERT INTO `map_shahe` VALUES (82, 1, 566.1, 17.4, 80, 0, 90.9, 0.83, 0, -1, 0, 0, 83, 0, 50.5, 0.83, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (83, 1, 531.8, 6.5, 81, 0, 50.5, 0.83, 0, -1, 0, 0, 0, -1, 0, 0, 41, 0, 76.7, 0.83);
INSERT INTO `map_shahe` VALUES (84, 1, 756.3, 430.4, 0, -1, 0, 0, 89, 0, 171.8, 1, 73, 1, 80.8, 0.96, 72, 1, 115.2, 0.14);
INSERT INTO `map_shahe` VALUES (85, 1, 655, 292.6, 94, 1, 50.5, 0.43, 95, 1, 101, 0.43, 96, 1, 50.5, 0.43, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (86, 1, 732.1, 538.1, 0, -1, 0, 0, 87, 1, 101, 0.89, 0, -1, 0, 0, 74, 1, 101, 0.89);
INSERT INTO `map_shahe` VALUES (87, 1, 821.4, 560.5, 0, -1, 0, 0, 0, -1, 0, 0, 88, 1, 111.1, 0.89, 86, 1, 101, 0.89);
INSERT INTO `map_shahe` VALUES (88, 1, 807.6, 444.7, 87, 1, 111.1, 0.89, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (89, 1, 907.9, 390, 90, 0, 161.7, 0.99, 99, 0, 129.3, 1, 100, 0, 40.4, 0.86, 89, 0, 171.8, 1);
INSERT INTO `map_shahe` VALUES (90, 1, 907.9, 643.1, 0, -1, 0, 0, 0, -1, 0, 0, 90, 0, 161.7, 0.99, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (91, 1, 893.4, 195.2, 98, 1, 34.3, 0.43, 0, -1, 0, 0, 92, 0, 86.4, 0.86, 78, 0, 238.4, 0.83);
INSERT INTO `map_shahe` VALUES (92, 1, 893.4, 108.8, 91, 0, 86.4, 0.86, 103, 1, 20.2, 0.86, 93, 0, 87.1, 0.86, 81, 0, 238.4, 0.83);
INSERT INTO `map_shahe` VALUES (93, 1, 893.4, 21.7, 92, 0, 87.1, 0.86, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (94, 1, 698.1, 345.8, 73, 1, 60.6, 0.43, 97, 1, 161.7, 0.11, 95, 1, 80.8, 0.43, 85, 1, 50.5, 0.43);
INSERT INTO `map_shahe` VALUES (95, 1, 763.6, 292.6, 94, 1, 80.8, 0.43, 0, -1, 0, 0, 85, 1, 101, 0.43, 96, 1, 80.8, 0.43);
INSERT INTO `map_shahe` VALUES (96, 1, 698.1, 240.5, 95, 1, 80.8, 0.43, 98, 1, 161.7, 0.11, 78, 1, 60.6, 0.43, 85, 1, 50.5, 0.43);
INSERT INTO `map_shahe` VALUES (97, 1, 859.8, 345.8, 0, -1, 0, 0, 100, 1, 52.5, 0.86, 98, 1, 97, 0.43, 94, 1, 161.7, 0.11);
INSERT INTO `map_shahe` VALUES (98, 1, 859.8, 248.8, 97, 1, 97, 0.43, 91, 1, 34.3, 0.43, 0, -1, 0, 0, 96, 1, 161.7, 0.11);
INSERT INTO `map_shahe` VALUES (99, 1, 1037.2, 390, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 89, 0, 129.3, 1);
INSERT INTO `map_shahe` VALUES (100, 1, 929.1, 345.8, 89, 1, 40.4, 0.86, 101, 1, 70.7, 0.86, 101, 1, 70.7, 0.86, 102, 1, 70.7, 0.86);
INSERT INTO `map_shahe` VALUES (101, 1, 997.1, 292.6, 100, 1, 70.7, 0.86, 0, -1, 0, 0, 102, 1, 70.7, 0.86, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (102, 1, 997.1, 221.9, 100, 1, 10.7, 0.86, 101, 1, 70.7, 0.86, 104, 1, 40.4, 0.86, 103, 1, 50.5, 0.86);
INSERT INTO `map_shahe` VALUES (103, 1, 997.1, 171.4, 102, 1, 50.5, 0.86, 104, 1, 40.4, 0.86, 92, 1, 20.2, 0.86, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (104, 1, 1015.5, 196.2, 102, 1, 40.4, 0.86, 0, -1, 0, 0, 103, 1, 40.4, 0.86, 0, -1, 0, 0);
INSERT INTO `map_shahe` VALUES (105, 1, 546.2, 442.5, 66, 0, 60.6, 0.56, 70, 0, 52.5, 0.37, 71, 1, 60.6, 0.14, 67, 0, 50.5, 0.37);

-- ----------------------------
-- Table structure for map_xitucheng
-- ----------------------------
DROP TABLE IF EXISTS `map_xitucheng`;
CREATE TABLE `map_xitucheng`  (
  `number` int NOT NULL,
  `isShaHe` tinyint NOT NULL,
  `abscissa` double NOT NULL,
  `ordinate` double NOT NULL,
  `number_1` int NOT NULL,
  `road_1.forWalk` int NOT NULL,
  `road_1.distance` double NOT NULL,
  `road_1.crowd` double NOT NULL,
  `number_2` int NOT NULL,
  `road_2.forWalk` int NOT NULL,
  `road_2.distance` double NOT NULL,
  `road_2.crowd` double NOT NULL,
  `number_3` int NOT NULL,
  `road_3.forWalk` int NOT NULL,
  `road_3.distance` double NOT NULL,
  `road_3.crowd` double NOT NULL,
  `number_4` int NOT NULL,
  `road_4.forWalk` int NOT NULL,
  `road_4.distance` double NOT NULL,
  `road_4.crowd` double NOT NULL,
  PRIMARY KEY (`number`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of map_xitucheng
-- ----------------------------
INSERT INTO `map_xitucheng` VALUES (1, 0, 231.1, 837.1, 0, 0, 0, 0, 56, 0, 348.5, 0.83, 2, 0, 15.2, 0.96, 57, 0, 231.1, 0.83);
INSERT INTO `map_xitucheng` VALUES (2, 0, 231.1, 821.9, 1, 0, 15.2, 0.96, 0, -1, 0, 0, 7, 0, 60.6, 0.96, 3, 1, 94.7, 0.42);
INSERT INTO `map_xitucheng` VALUES (3, 0, 136.4, 821.9, 0, -1, 0, 0, 2, 1, 94.7, 0.42, 4, 1, 34.1, 0.42, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (4, 0, 136.4, 787.8, 3, 1, 34.1, 0.42, 0, -1, 0, 0, 5, 1, 41.7, 0.42, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (5, 0, 136.4, 746.1, 4, 1, 41.7, 0.42, 8, 1, 94.7, 0.42, 10, 1, 49.2, 0.42, 6, 1, 81.4, 0.42);
INSERT INTO `map_xitucheng` VALUES (6, 0, 55, 746.1, 0, -1, 0, 0, 5, 1, 81.4, 0.42, 9, 1, 49.2, 0.58, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (7, 0, 231.1, 761.3, 2, 0, 60.6, 0.96, 21, 0, 94.7, 0.67, 8, 0, 15.2, 0.96, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (8, 0, 231.1, 746.1, 7, 0, 15.2, 0.96, 0, -1, 0, 0, 11, 0, 49.2, 0.96, 5, 1, 94.7, 0.42);
INSERT INTO `map_xitucheng` VALUES (9, 0, 55, 696.9, 6, 1, 49.2, 0.58, 10, 1, 81.4, 0.58, 12, 1, 36, 0.58, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (10, 0, 136.4, 696.9, 5, 1, 49.2, 0.43, 11, 1, 94.7, 0.58, 13, 1, 36, 0.42, 9, 1, 81.4, 0.58);
INSERT INTO `map_xitucheng` VALUES (11, 0, 231.1, 696.9, 8, 0, 49.2, 0.96, 26, 0, 178.1, 0.67, 14, 0, 36, 0.96, 10, 1, 94.7, 0.58);
INSERT INTO `map_xitucheng` VALUES (12, 0, 55, 660.9, 6, 1, 36, 0.58, 13, 1, 81.4, 0.42, 15, 1, 42.7, 0.58, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (13, 0, 136.4, 660.9, 10, 1, 36, 0.42, 14, 1, 94.7, 0.42, 16, 1, 41.7, 0.42, 12, 1, 81.4, 0.42);
INSERT INTO `map_xitucheng` VALUES (14, 0, 231.1, 660.9, 11, 0, 36, 0.96, 0, -1, 0, 0, 17, 0, 41.7, 0.96, 13, 1, 94.7, 0.42);
INSERT INTO `map_xitucheng` VALUES (15, 0, 55, 619.2, 12, 1, 41.7, 0.58, 16, 1, 81.4, 0.42, 18, 1, 102.3, 0.58, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (16, 0, 136.4, 619.2, 13, 1, 41.7, 0.42, 17, 1, 94.7, 0.42, 19, 1, 102.3, 0.42, 15, 1, 81.4, 0.42);
INSERT INTO `map_xitucheng` VALUES (17, 0, 231.1, 619.2, 14, 0, 41.7, 0.96, 27, 0, 178.1, 0.67, 20, 0, 102.3, 0.96, 16, 1, 81.4, 0.42);
INSERT INTO `map_xitucheng` VALUES (18, 0, 55, 516.9, 15, 1, 102.3, 0.58, 19, 1, 81.4, 0.58, 33, 1, 108, 0.58, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (19, 0, 136.4, 516.9, 16, 1, 102.3, 0.42, 20, 1, 94.7, 0.58, 0, -1, 0, 0, 18, 1, 81.4, 0.58);
INSERT INTO `map_xitucheng` VALUES (20, 0, 231.1, 516.9, 17, 0, 102.3, 0.96, 30, 0, 178.1, 0.67, 34, 0, 108, 0.96, 19, 1, 94.7, 0.58);
INSERT INTO `map_xitucheng` VALUES (21, 0, 325.8, 761.3, 22, 1, 56.8, 0.23, 23, 0, 83.8, 0.67, 0, -1, 0, 0, 7, 0, 94.7, 0.67);
INSERT INTO `map_xitucheng` VALUES (22, 0, 325.8, 818.1, 0, -1, 0, 0, 0, -1, 0, 0, 21, 1, 56.8, 0.23, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (23, 0, 409.1, 761.3, 24, 0, 64.4, 0.67, 28, 0, 161, 0.67, 26, 0, 64.4, 0.67, 21, 0, 83.3, 0.67);
INSERT INTO `map_xitucheng` VALUES (24, 0, 409.1, 825.7, 0, -1, 0, 0, 0, -1, 0, 0, 23, 0, 64.4, 0.67, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (25, 0, 579.6, 761.3, 56, 0, 75.8, 0.83, 0, 0, 0, 0, 32, 0, 244.4, 0.83, 28, 1, 9.5, 0.33);
INSERT INTO `map_xitucheng` VALUES (26, 0, 409.1, 696.9, 23, 0, 64.4, 0.67, 0, -1, 0, 0, 27, 0, 77.7, 0.67, 11, 0, 178.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (27, 0, 409.1, 619.2, 26, 0, 77.7, 0.67, 58, 0, 106.1, 0.67, 30, 0, 102.3, 0.67, 17, 0, 178.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (28, 0, 570.1, 761.3, 0, -1, 0, 0, 25, 1, 9.5, 0.33, 29, 1, 142.1, 0.33, 23, 0, 161, 0.67);
INSERT INTO `map_xitucheng` VALUES (29, 0, 570.1, 619.2, 28, 1, 142.1, 0.33, 0, -1, 0, 0, 0, -1, 0, 0, 58, 0, 54.9, 0.67);
INSERT INTO `map_xitucheng` VALUES (30, 0, 409.1, 516.9, 27, 0, 102.3, 0.67, 31, 0, 106.1, 0.67, 35, 0, 108, 0.67, 20, 0, 178.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (31, 0, 516, 516.9, 58, 0, 102.3, 0.67, 32, 0, 54.9, 0.67, 0, -1, 0, 0, 30, 0, 106.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (32, 0, 579.6, 516.9, 25, 0, 244.4, 0.83, 0, 0, 0, 0, 59, 0, 516.9, 0.83, 31, 0, 54.9, 0.67);
INSERT INTO `map_xitucheng` VALUES (33, 0, 55, 408.9, 18, 1, 108, 0.58, 34, 0, 176.1, 0.74, 40, 0, 58.8, 0.58, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (34, 0, 231.1, 408.9, 20, 0, 108, 0.96, 35, 0, 178.1, 0.67, 39, 0, 108, 0.96, 33, 0, 176.1, 0.74);
INSERT INTO `map_xitucheng` VALUES (35, 0, 409.1, 408.9, 30, 0, 108, 0.67, 36, 0, 87.1, 0.67, 38, 0, 108, 0.67, 34, 0, 178.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (36, 0, 469.2, 408.9, 0, -1, 0, 0, 0, -1, 0, 0, 37, 0, 108, 0.67, 35, 0, 87.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (37, 0, 469.2, 300.9, 36, 0, 108, 0.67, 0, -1, 0, 0, 48, 0, 96.6, 0.67, 38, 0, 871, 0.67);
INSERT INTO `map_xitucheng` VALUES (38, 0, 409.1, 300.9, 35, 0, 108, 0.67, 37, 0, 87.1, 0.67, 44, 0, 96.6, 0.67, 39, 0, 178.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (39, 0, 231.1, 300.9, 34, 0, 108, 0.96, 38, 0, 178.1, 0.67, 43, 0, 96.6, 0.96, 42, 0, 176.1, 0.74);
INSERT INTO `map_xitucheng` VALUES (40, 0, 55, 350.1, 33, 0, 58.8, 0.58, 0, -1, 0, 0, 42, 0, 49.1, 0.58, 41, 0, 45.5, 0.96);
INSERT INTO `map_xitucheng` VALUES (41, 0, 0, 350.1, 57, 0, 488.6, 0.83, 40, 0, 45.5, 0.96, 54, 0, 348.5, 0.83, 0, 0, 0, 0);
INSERT INTO `map_xitucheng` VALUES (42, 0, 55, 300.9, 40, 0, 49.2, 0.58, 39, 0, 176.1, 0.74, 59, 0, 96.6, 0.58, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (43, 0, 231.1, 204.3, 39, 0, 96.6, 0.96, 44, 0, 178.1, 0.67, 46, 0, 39.8, 0.96, 59, 0, 176.1, 0.74);
INSERT INTO `map_xitucheng` VALUES (44, 0, 409.1, 204.3, 38, 0, 96.6, 0.67, 45, 0, 87.1, 0.67, 0, -1, 0, 0, 43, 0, 178.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (45, 0, 469.2, 204.3, 37, 0, 96.6, 0.67, 0, -1, 0, 0, 0, -1, 0, 0, 44, 0, 87.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (46, 0, 231.1, 164.5, 43, 0, 39.8, 0.96, 48, 0, 284.1, 0.55, 51, 0, 123.1, 0.96, 47, 0, 162.9, 0.55);
INSERT INTO `map_xitucheng` VALUES (47, 0, 68.2, 164.5, 0, -1, 0, 0, 46, 0, 162.9, 0.55, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (48, 0, 515.2, 164.5, 0, -1, 0, 0, 0, -1, 0, 0, 49, 0, 77.7, 0.55, 46, 0, 284.1, 0.55);
INSERT INTO `map_xitucheng` VALUES (49, 0, 515.2, 86.8, 48, 0, 77.7, 0.55, 50, 0, 64.4, 0.55, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (50, 0, 579.6, 86.8, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 49, 0, 64.4, 0.55);
INSERT INTO `map_xitucheng` VALUES (51, 0, 231.1, 41.1, 46, 0, 0.96, 123.1, 52, 0, 81.4, 0.75, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (52, 0, 312.5, 41.4, 0, -1, 0, 0, 0, -1, 0, 0, 53, 0, 41.4, 0.75, 51, 0, 81.4, 0.75);
INSERT INTO `map_xitucheng` VALUES (53, 0, 312.5, 0, 52, 0, 41.4, 0.75, 55, 0, 269, 0.83, 0, 0, 0, 0, 54, 0, 310.6, 0.83);
INSERT INTO `map_xitucheng` VALUES (54, 0, 0, 0, 41, 0, 348.5, 0.83, 53, 0, 310.6, 0.83, 0, -1, 0, 0, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (55, 0, 579.6, 0, 32, 0, 516.9, 0.83, 0, -1, 0, 0, 0, -1, 0, 0, 53, 0, 269, 0.83);
INSERT INTO `map_xitucheng` VALUES (56, 0, 579.6, 837.1, 0, -1, 0, 0, 0, -1, 0, 0, 25, 0, 75.8, 0.83, 1, 0, 348.5, 0.83);
INSERT INTO `map_xitucheng` VALUES (57, 0, 0, 837.1, 0, -1, 0, 0, 1, 0, 231.1, 0.83, 41, 0, 488.6, 0.83, 0, -1, 0, 0);
INSERT INTO `map_xitucheng` VALUES (58, 0, 516, 619.2, 0, -1, 0, 0, 29, 0, 54.9, 0.67, 31, 0, 102.3, 0.67, 27, 0, 106.1, 0.67);
INSERT INTO `map_xitucheng` VALUES (59, 0, 55, 204.3, 42, 0, 96.6, 0.58, 43, 0, 176.1, 0.74, 0, -1, 0, 0, 0, -1, 0, 0);

-- ----------------------------
-- Table structure for people
-- ----------------------------
DROP TABLE IF EXISTS `people`;
CREATE TABLE `people`  (
  `number` int NOT NULL,
  `account` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `isAdmin` int NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `class` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of people
-- ----------------------------
INSERT INTO `people` VALUES (1, '2020211376', 'password', 0, '马天成', '2020211305');
INSERT INTO `people` VALUES (2, '2020211383', 'password', 0, '王宸', '2020211305');
INSERT INTO `people` VALUES (3, '2020211394', 'password', 0, '王陆萱', '2020211305');
INSERT INTO `people` VALUES (4, '4', '4', 1, '杨震', NULL);
INSERT INTO `people` VALUES (5, '5', '5', 1, '蒋砚军', NULL);
INSERT INTO `people` VALUES (6, '6', '6', 1, '周锋', NULL);
INSERT INTO `people` VALUES (7, '7', '7', 1, '左兴权', NULL);
INSERT INTO `people` VALUES (8, '8', '8', 1, '双锴', NULL);
INSERT INTO `people` VALUES (9, '9', '9', 1, '靳秀国', NULL);
INSERT INTO `people` VALUES (10, '10', '10', 1, '宋林泽', NULL);
INSERT INTO `people` VALUES (11, '2020211373', 'password', 0, '李祥宇', '2020211305');
INSERT INTO `people` VALUES (12, '2020211373', 'password', 0, '李润杰', '2020211304');

SET FOREIGN_KEY_CHECKS = 1;
