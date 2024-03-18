DESC topic;
INSERT INTO topic (title, description, created, author, profile) 
VALUES("MYSQL", "MYSQL is..", NOW(), "egoing", "developer")
SELECT  * FROM topic;
SELECT * FROM topic;
SELECT id,title,created,author FROM topic
SELECT id, title, created, author FROM topic WHERE author = "egoing"
SELECT id, title, created, author FROM topic WHERE author = "egoing" ORDER BY id DESC LIMIT 2
UPDATE topic SET description="Oracle is ...", title="Oracle" WHERE id=2
DELETE FROM topic WHERE id=5;
SELECT * FROM author
SELECT * FROM topic
SELECT * FROM topic LEFT JOIN author ON topic.author_id = author.id;
CREATE TABLE author (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `profile` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`id`)
);
 
--
-- Dumping data for table `author`
--
 
INSERT INTO `author` VALUES (1,'egoing','developer');
INSERT INTO author (id, name, profile) VALUES(1, "egoing", "developer");
INSERT INTO author(id, name, profile) VALUES (2,'duru','database administrator');
INSERT INTO author VALUES (3,'taeho','data scientist, developer');
 
--
-- Table structure for table `topic`
--
 
CREATE TABLE topic(
  id INT(11) NOT NULL AUTO_INCREMENT,
  title VARCHAR(30) NOT NULL,
  description TEXT NULL,
  created DATETIME NOT NULL,
  author_id INT(11) NULL,
  PRIMARY KEY (id)
);
DESC topic;
--
-- Dumping data for table `topic`
--
 
INSERT INTO topic(id, title, description, created, author_id) VALUES (1,'MySQL','MySQL is...','2018-01-01 12:10:11',1);
INSERT INTO topic(id, title, dexcription, created, author_id) VALUES (2,'Oracle','Oracle is ...','2018-01-03 13:01:10',1);
INSERT INTO `topic` VALUES (3,'SQL Server','SQL Server is ...','2018-01-20 11:01:10',2);
INSERT INTO `topic` VALUES (4,'PostgreSQL','PostgreSQL is ...','2018-01-23 01:03:03',3);
INSERT INTO `topic` VALUES (5,'MongoDB','MongoDB is ...','2018-01-30 12:31:03',1);
SELECT * FROM topic LEFT JOIN author ON topic.author_id = author.id;
SELECT * FROM topic LEFT JOIN author ON topic.author_id = author.id;
SELECT topic.id AS topic_id, title, description, created, name, profile FROM topic LEFT JOIN author ON topic.author_id = author.id;
SELECT comment.id, description, name, profile FROM comment LEFT JOIN author ON comment.author_id = author.id;
UPDATE author SET profile