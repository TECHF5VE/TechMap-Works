/*
SQLyog Ultimate v13.1.1 (64 bit)
MySQL - 5.7.28-log : Database - mybatis
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`mybatis` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `mybatis`;

/*Table structure for table `book_user` */

DROP TABLE IF EXISTS `book_user`;

CREATE TABLE `book_user` (
  `uid` int(11) DEFAULT NULL,
  `bid` int(11) DEFAULT NULL,
  KEY `uid` (`uid`),
  KEY `bid` (`bid`),
  CONSTRAINT `book_user_ibfk_1` FOREIGN KEY (`uid`) REFERENCES `user1` (`id`),
  CONSTRAINT `book_user_ibfk_2` FOREIGN KEY (`bid`) REFERENCES `books` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `book_user` */

insert  into `book_user`(`uid`,`bid`) values 
(1,11),
(1,12),
(1,14),
(1,4),
(1,3),
(1,2),
(1,1);

/*Table structure for table `books` */

DROP TABLE IF EXISTS `books`;

CREATE TABLE `books` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `book_name` varchar(32) DEFAULT NULL,
  `description` varchar(100) DEFAULT '无',
  PRIMARY KEY (`id`),
  UNIQUE KEY `book_name` (`book_name`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;

/*Data for the table `books` */

insert  into `books`(`id`,`book_name`,`description`) values 
(1,'《射雕英雄传》','无'),
(2,'《神雕侠侣》','无'),
(3,'《倚天屠龙记》','无'),
(4,'《天龙八部》','无'),
(5,'《笑傲江湖》','无'),
(6,'《鹿鼎记》','无'),
(7,'《雪山飞狐》','无'),
(8,'《书剑恩仇录》','无'),
(9,'《大道朝天》','无'),
(10,'《择天记》','无'),
(11,'《将夜》','无'),
(12,'《间客》','无'),
(13,'《庆余年》','无'),
(14,'《朱雀记》','无');

/*Table structure for table `user1` */

DROP TABLE IF EXISTS `user1`;

CREATE TABLE `user1` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(32) DEFAULT NULL,
  `password` varchar(32) DEFAULT NULL,
  `email` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

/*Data for the table `user1` */

insert  into `user1`(`id`,`username`,`password`,`email`) values 
(1,'dgb','123','1252294256@qq.com'),
(2,'ddd','123','111@qq.com'),
(3,'aaa','123','123@qq.com');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
