
DROP TABLE IF EXISTS `pokemon`;
DROP TABLE IF EXISTS `pokemon_types`;
DROP TABLE IF EXISTS `pokemon_evolutions`;
DROP TABLE IF EXISTS `pokemon_moves`;
DROP TABLE IF EXISTS `pokemon_routes`;
DROP TABLE IF EXISTS `trainer`;
DROP TABLE IF EXISTS `trainer_pokemon`;
DROP TABLE IF EXISTS `moves`;
DROP TABLE IF EXISTS `routes`;
DROP TABLE IF EXISTS `types`;


CREATE TABLE `pokemon`
(
	`pokemon_id` int(11) NOT NULL,
	`name` varchar(255) NOT NULL,
	`description` varchar(255),
	PRIMARY KEY (`pokemon_id`),
	UNIQUE KEY (`name`)
)ENGINE=InnoDB;

CREATE TABLE `types`
(
	`type_id` int(11) NOT NULL AUTO_INCREMENT,
	`type_name` varchar(255) NOT NULL,
	PRIMARY KEY (`type_id`),
	UNIQUE KEY(`type_name`)
)ENGINE=InnoDB;

CREATE TABLE `routes`
(
	`route_id` int(11) NOT NULL AUTO_INCREMENT,
	`route_name` varchar(255) NOT NULL,
	`description` varchar(255),
	PRIMARY KEY (`route_id`),
	UNIQUE KEY (`route_name`)
)ENGINE=InnoDB;

CREATE TABLE `trainer`
(
	`trainer_id` int(11) NOT NULL AUTO_INCREMENT,
	`trainer_name` varchar(255) NOT NULL,
	`description` varchar(255),
	PRIMARY KEY (`trainer_id`),
	UNIQUE KEY(`trainer_name`)
)ENGINE=InnoDB;

CREATE TABLE `moves`
(
	`move_id` int(11) NOT NULL AUTO_INCREMENT,
	`move_name` varchar(255) NOT NULL,
	`move_type` int(11) NOT NULL,
	`move_base_damage` int(11) DEFAULT NULL,
	`move_pp` int(11) NOT NULL,
	`description` varchar(255),
	PRIMARY KEY(`move_id`),
	UNIQUE KEY(`move_name`),
	FOREIGN KEY(`move_type`) REFERENCES `types`(`type_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE
)ENGINE=InnoDB;

CREATE TABLE `trainer_pokemon`
(
	`trainer_pokemon_id` int(11) NOT NULL,
	`trainer_pokemon_type_id` int(11) NOT NULL,
	PRIMARY KEY(`trainer_pokemon_id`,`trainer_pokemon_type_id`),
	FOREIGN KEY (`trainer_pokemon_id`) REFERENCES `trainer` (`trainer_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	FOREIGN KEY(`trainer_pokemon_type_id`) REFERENCES `types` (`type_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE
)ENGINE=InnoDB;

CREATE TABLE `pokemon_routes`
(
	`pid` int(11) NOT NULL,
	`rid` int(11) NOT NULL,
	PRIMARY KEY (`pid`, `rid`),
	FOREIGN KEY (`pid`) REFERENCES `pokemon` (`pokemon_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	FOREIGN KEY (`rid`) REFERENCES `routes` (`route_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE
)ENGINE=InnoDB;

CREATE TABLE `pokemon_moves`
(
	`pid` int(11) NOT NULL,
	`mid` int(11) NOT NULL,
	PRIMARY KEY (`pid`, `mid`),
	FOREIGN KEY (`pid`) REFERENCES `pokemon` (`pokemon_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	FOREIGN KEY (`mid`) REFERENCES `moves` (`move_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE
)ENGINE=InnoDB;

CREATE TABLE `pokemon_evolutions`
(
	`pokemon_evolution_id` int(11) NOT NULL,
	`pokemon_predecessor_id` int(11) NOT NULL,
	PRIMARY KEY (`pokemon_evolution_id`, `pokemon_predecessor_id`),
	FOREIGN KEY (`pokemon_evolution_id`) REFERENCES `pokemon` (`pokemon_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	FOREIGN KEY (`pokemon_predecessor_id`) REFERENCES `pokemon` (`pokemon_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE
)ENGINE=InnoDB;

CREATE TABLE `pokemon_types`
(
	`pid` int(11) NOT NULL,
	`ptid` int(11) NOT NULL,
	PRIMARY KEY (`pid`, `ptid`),
	FOREIGN KEY (`pid`) REFERENCES `pokemon` (`pokemon_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	FOREIGN KEY (`ptid`) REFERENCES `types` (`type_id`)
		ON DELETE CASCADE
		ON UPDATE CASCADE
)ENGINE=InnoDB;


