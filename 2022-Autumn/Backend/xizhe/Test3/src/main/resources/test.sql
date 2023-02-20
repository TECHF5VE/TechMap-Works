/*
 Navicat Premium Data Transfer

 Source Server         : localhost_3306
 Source Server Type    : MySQL
 Source Server Version : 50536
 Source Host           : localhost:3306
 Source Schema         : test

 Target Server Type    : MySQL
 Target Server Version : 50536
 File Encoding         : 65001

 Date: 20/02/2023 15:55:56
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for class
-- ----------------------------
DROP TABLE IF EXISTS `class`;
CREATE TABLE `class`  (
  `id` int(11) NOT NULL,
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `school_id` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of class
-- ----------------------------
INSERT INTO `class` VALUES (1, '软件2001', 1);
INSERT INTO `class` VALUES (2, '软件2002', 1);
INSERT INTO `class` VALUES (3, '软件2003', 1);

-- ----------------------------
-- Table structure for school
-- ----------------------------
DROP TABLE IF EXISTS `school`;
CREATE TABLE `school`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 2 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of school
-- ----------------------------
INSERT INTO `school` VALUES (1, 'UJS');

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `sex` char(2) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `sno` char(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `class_id` int(11) NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 24 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES (1, '张三', '男', '32001', 1);
INSERT INTO `student` VALUES (2, '李四', '男', '32002', 1);
INSERT INTO `student` VALUES (3, '李红', '女', '32003', 1);
INSERT INTO `student` VALUES (4, '任昊焱', '男', '32004', 2);
INSERT INTO `student` VALUES (5, '于峻熙', '男', '32005', 2);
INSERT INTO `student` VALUES (6, '杨伟祺', '男', '32007', 2);
INSERT INTO `student` VALUES (7, '傅锦程', '男', '32010', 3);
INSERT INTO `student` VALUES (8, '李果', '男', '32777', 3);
INSERT INTO `student` VALUES (9, '张远航', '女', '32666', 2);
INSERT INTO `student` VALUES (10, '李梓晨', '女', '32555', 2);
INSERT INTO `student` VALUES (11, '李昊焱', '男', '32444', 3);
INSERT INTO `student` VALUES (12, '刘天磊', '男', '32333', 1);
INSERT INTO `student` VALUES (13, '崔熠彤', '女', '32221', 2);
INSERT INTO `student` VALUES (14, '宋浩轩', '女', '32111', 1);
INSERT INTO `student` VALUES (15, '吴健柏', '女', '32088', 2);
INSERT INTO `student` VALUES (16, '冯昊强', '男', '32099', 1);
INSERT INTO `student` VALUES (17, '杜睿渊', '女', '32017', 2);
INSERT INTO `student` VALUES (18, '李子默', '女', '32016', 1);
INSERT INTO `student` VALUES (19, '张鑫磊', '男', '32015', 2);
INSERT INTO `student` VALUES (20, '王越彬', '女', '32013', 1);
INSERT INTO `student` VALUES (21, '王锦程', '女', '32041', 2);
INSERT INTO `student` VALUES (22, '刘振家', '男', '32031', 1);
INSERT INTO `student` VALUES (23, '刘昊天', '男', '32022', 1);

SET FOREIGN_KEY_CHECKS = 1;
