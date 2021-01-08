CREATE TABLE `Account` (
  `id` int PRIMARY KEY,
  `email` varchar(255) UNIQUE,
  `password` varchar(255)
);

CREATE TABLE `Character` (
  `id` int PRIMARY KEY,
  `account_id` int COMMENT 'null if NPC',
  `inventory_id` int,
  `title` ENUM ('Emperor', 'Grand_Inquisitor', 'Imperator', 'Trooper', 'President', 'Senator', 'Marshal', 'Ranger', 'High_Lord', 'Lord', 'Paladin', 'Consul', 'Member'),
  `HP` int,
  `armor` int,
  `shields` int,
  `sex` ENUM ('Male', 'Female', 'Asexual'),
  `species` species,
  `vitality` int,
  `strength` int,
  `speed` int,
  `intelligence` int,
  `charisma` int,
  `wisdom` int,
  `biography` varchar(255),
  `crew_id` int,
  `profession` ENUM ('Trader', 'Mechanic', 'Pirate', 'Traveler', 'Craftsman', 'Gunslinger', 'Swordsman') COMMENT 'if NPC',
  `location` ENUM ('Bar', 'Hangar', 'Trading_Post', 'Bank', 'Junkyard', 'Black_Market', 'Refinery', 'Manufactory', 'Planet', 'Shipyard', 'Space_Station', 'Space_Dock', 'Starbase', 'Ship', 'Space', 'Home'),
  `location_id` int COMMENT 'references an id of a relevant location. For example, an outpost, facility or ship id.',
  `bookmarks_id` int,
  `x` decimal,
  `y` decimal,
  `hidden` boolean
);

CREATE TABLE `CharacterList` (
  `id` int,
  `character_id` int
);

CREATE TABLE `Quarters` (
  `id` int PRIMARY KEY,
  `type` ENUM ('Bar', 'Hangar', 'Trading_Post', 'Bank', 'Junkyard', 'Black_Market', 'Refinery', 'Manufactory', 'Planet', 'Shipyard', 'Space_Station', 'Space_Dock', 'Starbase', 'Ship', 'Space', 'Home'),
  `character_list_id` int,
  `capacity` int
);

CREATE TABLE `Species` (
  `type` ENUM ('Human', 'AI', 'Feline', 'Apex', 'Salarian', 'Menal', 'Killix'),
  `modifier_id` int
);

CREATE TABLE `Modifier` (
  `id` int PRIMARY KEY,
  `vitality` int,
  `strength` int,
  `speed` int,
  `intelligence` int,
  `charisma` int,
  `wisdom` int,
  `mass` int,
  `hull` int,
  `module_slots` int,
  `weapon_slots` int,
  `subsystems` int,
  `quarters_capacity` int,
  `fighter_bay_capacity` int,
  `cargo_capacity` int,
  `attack` int,
  `armor` int,
  `shield` int
);

CREATE TABLE `Bounty` (
  `id` int PRIMARY KEY,
  `character_id` int,
  `amount` decimal,
  `dead_or_alive` ENUM ('Dead', 'Alive', 'Dead_Or_Alive')
);

CREATE TABLE `Inventory` (
  `id` int PRIMARY KEY,
  `character_id` int,
  `list_id` int,
  `capacity` int
);

CREATE TABLE `Cargo` (
  `id` int PRIMARY KEY,
  `list_id` int,
  `capacity` int
);

CREATE TABLE `ItemList` (
  `id` int,
  `item_id` int,
  `quantity` int
);

CREATE TABLE `Item` (
  `id` int PRIMARY KEY,
  `character_id` int,
  `name` varchar(255),
  `color` varchar(255),
  `description` varchar(255),
  `type` ENUM ('Schematic', 'Ore', 'Spice', 'Commodity', 'Luxury', 'Alloy', 'Part', 'Ship', 'Weapon', 'Gear', 'Tool', 'Document', 'Slave', 'Art'),
  `rarity` ENUM ('Fake', 'Common', 'Uncommon', 'Superior', 'Rare', 'Mythic', 'Legendary', 'Primordial'),
  `mass` int,
  `integrity` int,
  `modifier_id` int
);

CREATE TABLE `Starship` (
  `id` int PRIMARY KEY,
  `character_id` int,
  `ship_type` ENUM ('Battle_Carrier', 'Battleship', 'Blockade_Runner', 'Capital_Ship', 'Command_Ship', 'Corsair', 'Corvette', 'Cruiser', 'Destroyer', 'Dreadnaught', 'Freighter', 'Frigate', 'Grand_Liner', 'Gunship', 'Heavy_Cruiser', 'Heavy_Freighter', 'Heavy_Miner', 'Light_Miner'),
  `name` varchar(255),
  `color` varchar(255),
  `description` varchar(255),
  `schematic_id` int,
  `cargo_id` int,
  `module_list` int,
  `module_slots` int,
  `weapon_slots` int,
  `subsystems` int,
  `quarters_id` int,
  `mass` int,
  `speed` int,
  `hull` int,
  `fighter_bay` int,
  `fighters_id` int
);

CREATE TABLE `Schematic` (
  `id` int PRIMARY KEY,
  `list_id` int
);

CREATE TABLE `UniverseMap` (
  `id` int PRIMARY KEY,
  `galaxy_id` int COMMENT 'Can contain 400 [20x20] quadrants, some of which can contain star systems',
  `quadrant_id` int COMMENT 'Can contain 400 [20x20] sectors, some of which contain celestial objects',
  `sector_id` int COMMENT 'Can contain asteroids, planets, stars or outposts'
);

CREATE TABLE `Galaxy` (
  `id` int PRIMARY KEY,
  `name` varchar(255),
  `description` varchar(255),
  `x` int,
  `y` int
);

CREATE TABLE `Quadrant` (
  `id` int PRIMARY KEY,
  `x` decimal,
  `y` decimal
);

CREATE TABLE `Sector` (
  `id` int PRIMARY KEY,
  `quarters_id` int,
  `x` decimal,
  `y` decimal
);

CREATE TABLE `Planet` (
  `id` int PRIMARY KEY,
  `name` varchar(255),
  `type` ENUM ('Barren', 'Frozen', 'Cold', 'Temperate', 'Warm', 'Hot', 'Burning', 'Arctic', 'Snow', 'Tundra', 'Boreal', 'Steppes', 'Monsoon', 'Forest', 'Terran', 'Ocean', 'Atoll', 'Savannah', 'Mediterranean', 'Jungle', 'Desert', 'Arid', 'Ash', 'Lava'),
  `size` int COMMENT 'scale of 1-100',
  `description` varchar(255),
  `government` ENUM ('Empire', 'Republic', 'Council', 'No_Government'),
  `bank_id` int,
  `market_id` int,
  `black_market_id` int,
  `leader` int,
  `quarters_id` int,
  `bar_quarters` int,
  `hangar_quarters` int,
  `hangar_cargo` int,
  `trading_post_quarters` int,
  `bank_quarters` int,
  `junkyard_quarters` int,
  `black_market_quarters` int,
  `guards` int,
  `x` decimal,
  `y` decimal
);

CREATE TABLE `Asteroid` (
  `id` int PRIMARY KEY,
  `cargo_id` int,
  `x` int,
  `y` int
);

CREATE TABLE `Government` (
  `id` int PRIMARY KEY,
  `type` ENUM ('Empire', 'Republic', 'Council', 'No_Government'),
  `planet_id` int,
  `leader` int,
  `tax_rate` decimal,
  `bank_id` int,
  `territory_id` int,
  `description` varchar(255)
);

CREATE TABLE `Territory` (
  `id` int,
  `sector_list_id` int
);

CREATE TABLE `Sector_List` (
  `id` int,
  `sector_id` int
);

CREATE TABLE `Comms` (
  `id` int PRIMARY KEY,
  `planet_id` int,
  `reply` int,
  `author` int,
  `message` varchar(255),
  `posted` timestamp
);

CREATE TABLE `MostWanted` (
  `id` int PRIMARY KEY,
  `planet_id` int,
  `bounty_id` int
);

CREATE TABLE `MarketOrder` (
  `id` int PRIMARY KEY,
  `type` ENUM ('Buy', 'Sell'),
  `item_id` int,
  `item_type` ENUM ('Schematic', 'Ore', 'Spice', 'Commodity', 'Luxury', 'Alloy', 'Part', 'Ship', 'Weapon', 'Gear', 'Tool', 'Document', 'Slave', 'Art'),
  `rarity` ENUM ('Fake', 'Common', 'Uncommon', 'Superior', 'Rare', 'Mythic', 'Legendary', 'Primordial'),
  `quantity` int,
  `price` decimal,
  `expires` int,
  `time` timestamp
);

CREATE TABLE `Orders` (
  `id` int PRIMARY KEY,
  `market_id` int,
  `order_id` int
);

CREATE TABLE `Market` (
  `id` int PRIMARY KEY,
  `illegal` boolean COMMENT 'determines if this is a black market, allowing illegal goods',
  `orders_id` int
);

CREATE TABLE `Bank` (
  `id` int PRIMARY KEY,
  `character_id` int,
  `funds` decimal
);

CREATE TABLE `Outposts` (
  `id` int PRIMARY KEY,
  `sector_id` int,
  `outpost_type` ENUM ('Refinery', 'Manufactory', 'Shipyard', 'Space_Station', 'Space_Dock', 'Starbase'),
  `market_id` int,
  `schematic_id` int,
  `cargo_id` int,
  `module_list` int,
  `guards` int,
  `module_slots` int,
  `weapon_slots` int,
  `subsystems` int,
  `quarters_id` int,
  `mass` int,
  `speed` int,
  `hull` int,
  `fighter_bay` int,
  `fighters_id` int,
  `x` decimal,
  `y` decimal
);

CREATE TABLE `Organization` (
  `id` int PRIMARY KEY,
  `secret` boolean,
  `alliance_id` int,
  `character_list_id` int,
  `applications_id` int,
  `invitations_id` int,
  `leader` int,
  `territory_id` int,
  `founded` datetime,
  `dues` decimal
);

CREATE TABLE `Organization_List` (
  `id` int,
  `organization_id` int
);

CREATE TABLE `Alliance_List` (
  `id` int,
  `alliance_id` int
);

CREATE TABLE `Coalition` (
  `id` int PRIMARY KEY,
  `name` varchar(255),
  `description` varchar(255),
  `founded` datetime,
  `disbanded` datetime,
  `members_id` int,
  `applications_id` int,
  `invitations_id` int
);

CREATE TABLE `Alliance` (
  `id` int PRIMARY KEY,
  `colition_id` int,
  `name` varchar(255),
  `description` varchar(255),
  `founded` datetime,
  `disbanded` datetime,
  `members_id` int,
  `applications_id` int,
  `invitations_id` int
);

CREATE TABLE `Coalition_War` (
  `id` int PRIMARY KEY,
  `name` varchar(255),
  `description` varchar(255),
  `declared_by` int,
  `against` int,
  `start` datetime,
  `end` datetime
);

CREATE TABLE `Alliance_War` (
  `id` int PRIMARY KEY,
  `name` varchar(255),
  `description` varchar(255),
  `declared_by` int,
  `against` int,
  `start` datetime,
  `end` datetime
);

CREATE TABLE `Organization_War` (
  `id` int PRIMARY KEY,
  `name` varchar(255),
  `description` varchar(255),
  `declared_by` int,
  `against` int,
  `start` datetime,
  `end` datetime
);

CREATE TABLE `Ranks` (
  `id` int PRIMARY KEY,
  `organization_id` int,
  `level` int,
  `name` varchar(255),
  `description` varchar(255)
);

CREATE TABLE `Attacks` (
  `id` int PRIMARY KEY,
  `attacker` int,
  `type` ENUM ('Character', 'Ship', 'Plunder', 'Blockade', 'Board', 'Infiltrate', 'Outpost', 'Counter'),
  `time` datetime,
  `target_id` int COMMENT 'Id of the target, depending on attack type',
  `hp_damage` int,
  `hull_damage` int,
  `armor_damage` int,
  `shield_damage` int
);

ALTER TABLE `Character` ADD FOREIGN KEY (`account_id`) REFERENCES `Account` (`id`);

ALTER TABLE `Character` ADD FOREIGN KEY (`inventory_id`) REFERENCES `Inventory` (`id`);

ALTER TABLE `Character` ADD FOREIGN KEY (`crew_id`) REFERENCES `CharacterList` (`id`);

ALTER TABLE `Character` ADD FOREIGN KEY (`bookmarks_id`) REFERENCES `Sector_List` (`id`);

ALTER TABLE `CharacterList` ADD FOREIGN KEY (`character_id`) REFERENCES `Character` (`id`);

ALTER TABLE `Quarters` ADD FOREIGN KEY (`character_list_id`) REFERENCES `CharacterList` (`id`);

ALTER TABLE `Species` ADD FOREIGN KEY (`modifier_id`) REFERENCES `Modifier` (`id`);

ALTER TABLE `Bounty` ADD FOREIGN KEY (`character_id`) REFERENCES `Character` (`id`);

ALTER TABLE `Inventory` ADD FOREIGN KEY (`character_id`) REFERENCES `Character` (`id`);

ALTER TABLE `ItemList` ADD FOREIGN KEY (`id`) REFERENCES `Inventory` (`list_id`);

ALTER TABLE `ItemList` ADD FOREIGN KEY (`id`) REFERENCES `Cargo` (`list_id`);

ALTER TABLE `ItemList` ADD FOREIGN KEY (`item_id`) REFERENCES `Item` (`id`);

ALTER TABLE `Item` ADD FOREIGN KEY (`character_id`) REFERENCES `Character` (`id`);

ALTER TABLE `Item` ADD FOREIGN KEY (`modifier_id`) REFERENCES `Modifier` (`id`);

ALTER TABLE `Starship` ADD FOREIGN KEY (`character_id`) REFERENCES `Character` (`id`);

ALTER TABLE `Starship` ADD FOREIGN KEY (`schematic_id`) REFERENCES `Schematic` (`id`);

ALTER TABLE `Starship` ADD FOREIGN KEY (`cargo_id`) REFERENCES `Cargo` (`id`);

ALTER TABLE `Starship` ADD FOREIGN KEY (`module_list`) REFERENCES `ItemList` (`id`);

ALTER TABLE `Starship` ADD FOREIGN KEY (`quarters_id`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Starship` ADD FOREIGN KEY (`fighters_id`) REFERENCES `ItemList` (`id`);

ALTER TABLE `Schematic` ADD FOREIGN KEY (`list_id`) REFERENCES `ItemList` (`id`);

ALTER TABLE `UniverseMap` ADD FOREIGN KEY (`galaxy_id`) REFERENCES `Galaxy` (`id`);

ALTER TABLE `UniverseMap` ADD FOREIGN KEY (`quadrant_id`) REFERENCES `Quadrant` (`id`);

ALTER TABLE `UniverseMap` ADD FOREIGN KEY (`sector_id`) REFERENCES `Sector` (`id`);

ALTER TABLE `Sector` ADD FOREIGN KEY (`quarters_id`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`bank_id`) REFERENCES `Bank` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`market_id`) REFERENCES `Market` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`black_market_id`) REFERENCES `Market` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`leader`) REFERENCES `Character` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`quarters_id`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`bar_quarters`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`hangar_quarters`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`hangar_cargo`) REFERENCES `Cargo` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`trading_post_quarters`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`bank_quarters`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`junkyard_quarters`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`black_market_quarters`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Planet` ADD FOREIGN KEY (`guards`) REFERENCES `CharacterList` (`id`);

ALTER TABLE `Asteroid` ADD FOREIGN KEY (`cargo_id`) REFERENCES `Cargo` (`id`);

ALTER TABLE `Government` ADD FOREIGN KEY (`planet_id`) REFERENCES `Planet` (`id`);

ALTER TABLE `Government` ADD FOREIGN KEY (`leader`) REFERENCES `Character` (`id`);

ALTER TABLE `Government` ADD FOREIGN KEY (`bank_id`) REFERENCES `Bank` (`id`);

ALTER TABLE `Government` ADD FOREIGN KEY (`territory_id`) REFERENCES `Territory` (`id`);

ALTER TABLE `Sector_List` ADD FOREIGN KEY (`sector_id`) REFERENCES `Sector` (`id`);

ALTER TABLE `Comms` ADD FOREIGN KEY (`planet_id`) REFERENCES `Planet` (`id`);

ALTER TABLE `Comms` ADD FOREIGN KEY (`reply`) REFERENCES `Comms` (`id`);

ALTER TABLE `Comms` ADD FOREIGN KEY (`author`) REFERENCES `Character` (`id`);

ALTER TABLE `MostWanted` ADD FOREIGN KEY (`planet_id`) REFERENCES `Planet` (`id`);

ALTER TABLE `MostWanted` ADD FOREIGN KEY (`bounty_id`) REFERENCES `Bounty` (`id`);

ALTER TABLE `MarketOrder` ADD FOREIGN KEY (`item_id`) REFERENCES `Item` (`id`);

ALTER TABLE `Orders` ADD FOREIGN KEY (`market_id`) REFERENCES `Market` (`id`);

ALTER TABLE `Orders` ADD FOREIGN KEY (`order_id`) REFERENCES `MarketOrder` (`id`);

ALTER TABLE `Orders` ADD FOREIGN KEY (`id`) REFERENCES `Market` (`orders_id`);

ALTER TABLE `Character` ADD FOREIGN KEY (`id`) REFERENCES `Bank` (`character_id`);

ALTER TABLE `Outposts` ADD FOREIGN KEY (`sector_id`) REFERENCES `Sector` (`id`);

ALTER TABLE `Outposts` ADD FOREIGN KEY (`market_id`) REFERENCES `Market` (`id`);

ALTER TABLE `Outposts` ADD FOREIGN KEY (`schematic_id`) REFERENCES `Schematic` (`id`);

ALTER TABLE `Outposts` ADD FOREIGN KEY (`cargo_id`) REFERENCES `Cargo` (`id`);

ALTER TABLE `Outposts` ADD FOREIGN KEY (`module_list`) REFERENCES `ItemList` (`id`);

ALTER TABLE `Outposts` ADD FOREIGN KEY (`guards`) REFERENCES `CharacterList` (`id`);

ALTER TABLE `Outposts` ADD FOREIGN KEY (`quarters_id`) REFERENCES `Quarters` (`id`);

ALTER TABLE `Outposts` ADD FOREIGN KEY (`fighters_id`) REFERENCES `ItemList` (`id`);

ALTER TABLE `Organization` ADD FOREIGN KEY (`alliance_id`) REFERENCES `Alliance` (`id`);

ALTER TABLE `Organization` ADD FOREIGN KEY (`character_list_id`) REFERENCES `CharacterList` (`id`);

ALTER TABLE `Organization` ADD FOREIGN KEY (`applications_id`) REFERENCES `CharacterList` (`id`);

ALTER TABLE `Organization` ADD FOREIGN KEY (`invitations_id`) REFERENCES `CharacterList` (`id`);

ALTER TABLE `Organization` ADD FOREIGN KEY (`leader`) REFERENCES `Character` (`id`);

ALTER TABLE `Organization` ADD FOREIGN KEY (`territory_id`) REFERENCES `Territory` (`id`);

ALTER TABLE `Organization_List` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization` (`id`);

ALTER TABLE `Alliance_List` ADD FOREIGN KEY (`alliance_id`) REFERENCES `Alliance` (`id`);

ALTER TABLE `Coalition` ADD FOREIGN KEY (`members_id`) REFERENCES `Alliance_List` (`id`);

ALTER TABLE `Coalition` ADD FOREIGN KEY (`applications_id`) REFERENCES `Alliance_List` (`id`);

ALTER TABLE `Coalition` ADD FOREIGN KEY (`invitations_id`) REFERENCES `Alliance_List` (`id`);

ALTER TABLE `Alliance` ADD FOREIGN KEY (`colition_id`) REFERENCES `Coalition` (`id`);

ALTER TABLE `Alliance` ADD FOREIGN KEY (`members_id`) REFERENCES `Organization_List` (`id`);

ALTER TABLE `Alliance` ADD FOREIGN KEY (`applications_id`) REFERENCES `Organization_List` (`id`);

ALTER TABLE `Alliance` ADD FOREIGN KEY (`invitations_id`) REFERENCES `Organization_List` (`id`);

ALTER TABLE `Coalition_War` ADD FOREIGN KEY (`declared_by`) REFERENCES `Coalition` (`id`);

ALTER TABLE `Coalition_War` ADD FOREIGN KEY (`against`) REFERENCES `Coalition` (`id`);

ALTER TABLE `Alliance_War` ADD FOREIGN KEY (`declared_by`) REFERENCES `Alliance` (`id`);

ALTER TABLE `Alliance_War` ADD FOREIGN KEY (`against`) REFERENCES `Alliance` (`id`);

ALTER TABLE `Organization_War` ADD FOREIGN KEY (`declared_by`) REFERENCES `Organization` (`id`);

ALTER TABLE `Organization_War` ADD FOREIGN KEY (`against`) REFERENCES `Organization` (`id`);

ALTER TABLE `Ranks` ADD FOREIGN KEY (`organization_id`) REFERENCES `Organization` (`id`);

ALTER TABLE `Attacks` ADD FOREIGN KEY (`attacker`) REFERENCES `Character` (`id`);

ALTER TABLE `Sector_List` ADD FOREIGN KEY (`id`) REFERENCES `Territory` (`sector_list_id`);
