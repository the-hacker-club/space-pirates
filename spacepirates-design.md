# Space Pirates Design

## Fundamental Elements

1. PCs
2. NPCs
3. Spaceships
4. Planets
5. Asteroids
6. Outpoosts
7. Goods
8. Skills
9. Basic Mechanics

## 1. PCs
    * AccountID
    * Stats
        - Current HP
        - Vitality
        - Strength
        - Speed
        - Intelligence
        - Charisma
        - Wisdom
    * Inventory
    * Bounties
    * Reputation
    * Credits
    * Quest
        - NPC quests include side missions PCs can accomplish
        - Quests also facilitate passengers

## 2. NPCs
    * See PCs

## 3. Spaceships
    * Type
    * Class
    * Make
    * Model
    * Inventory
    * Stats
        - Mass
        - Speed
        - Hull
        - Weapon Slots
        - Hardpoints
        - Fighter Bays
        - Quarters
        - Cargo Hold
        - Cost

## 4. Planets

Properties of planets:
    * [Leader](https://web.archive.org/web/20071214004743/http://wiki.chosenspace.com/index.php/Planet_Leader)
    * [Government](https://web.archive.org/web/20070513095310/http://wiki.chosenspace.com/index.php/Government)
        * [Planet Leader](https://web.archive.org/web/20071214004743/http://wiki.chosenspace.com/index.php/Planet_Leader)
        * Government Type
            - Empire
            - Republic
            - Councel
            - No government
        * Tax
        * Documents
        * Approval Rating
    * Population
    * Outposts
    * Spaceport
        - List of passengers

Government types are determined by [Election](https://web.archive.org/web/20070531214057/http://wiki.chosenspace.com/index.php/Election)

## 5. Asteroids

Asteroids contain a combination of ores, varying in rarity.

    * Zirconium
    * Gold
    * Iriium
    * Fullerite
    * Tetrium
    * Quadrium

## 6. Outposts

Outposts are space stations built by governments and factions in sectors they control.
    * Refineries
        - Shields
        - Defense
        - Integrity (Building HP)
        - Size
        - Efficiency
    * Manufactories
        - Shields
        - Defense
        - Integrity (Building HP)
        - Size
        - Efficiency
    * Shipyard
        - Ship Upgrades and purchase of new ships
    * Space Station
        - Repairs and Fuel
    * Trading Post
    * Planet Bank
    * Comms Board
    * SpaceStation
        - can offer certain outpost services

Planets also can have facilities which offer similar services.

    * Bar
        - Recruiting crew
        - Drinking
        - Bounties
        - Rumors
    * Hangar
        - Ship storage
    * Trading Post
        - View market orders
    * Bank
        - Can make deposits and withdraws

    * Junkyard
        - repairs
    * Comms board
    * Black Market
        - Only available after asking bartender
          - complete mission
          - bribe
          - intimidate

## 7. Goods

This is the basic mechanic underlying production of spaceships/space stations, etc.

    * Mine > Ore > Refinery > Alloy > Manufactory > Parts > Shipyard > Ships

There are different types of goods available on the market:

    * Illegal goods (Blackmarket)
    * Slaves (Blackmarket)
    * Spices (Blackmarket)
    * Documents (Blackmarket)
    * Spices
    * Commodities
    * Luxuries
    * Ores
    * Alloys
    * Parts
    * Ships
    * Weapons
    * Gear
    * Tools
    * Art

## 8. Skills

Skills define actions PCs and sometimes NPCs can perform. Skills success are derived from base stats.

    * Healing/Use Medicine
        - Wisdom + Vitality
    * Finese
        - Wisdom + Strength
    * Stealth
        - Wisdom + Speed
    * Trade
        - Wisdom + Charisma
    * Hack Systems
        - Wisdom + Intelligence
    * HP
        - Vitality + Strength
    * Reflexes
        - Vitality + Speed
    * Intimidate
        - Vitality + Charisma
    * Aim
        - Vitality + Intelligence
    * Attack (Melee)
        - Strength + Speed
    * Repair
        - Strength + Charisma
    * Crafting
        - Strength + Intelligence
    * Pilot Drone/Mine
        - Speed + Charisma
    * Attack (Ranged)
        - Speed + Intelligence
    * Negotiate
        - Charisma + Intelligence

## 9. Basic Mechanics

asteroids > ore > refine > alloys > manufactory > parts > shipyards > ships/outposts | tourism, pirating, mining | planets > governments > bounties > bank > control sectors > organizations > alliances > coalitions > war > attacking

## [Navigation](https://web.archive.org/web/20071006162317/http://wiki.chosenspace.com/index.php/Galactic_Map)

Galactic Map > Quadrant View > Sector View > Planet/Space Station

Coordinates are a collection of X:Y coordinates corresponding to:
```
GalaxyX:GalaxyY,QuadrantX:QuadrantY,SectorX:SectorY
```

From the database:
```
// Universe
// coordinates:  [note: 'universe coordinate and 6 decimals, 2 for each galaxy, quadrant, sector coordinate. ie: 010203']
// Start off with 40 galaxies
Table UniverseMap {
  id int [pk]
  galaxy_id int [ref: > Galaxy.id, note: 'Can contain 400 [20x20] quadrants, some of which can contain star systems']
  quadrant_id int [ref: > Quadrant.id, note: 'Can contain 400 [20x20] sectors, some of which contain celestial objects']
  sector_id int [ref: - Sector.id, note: 'Can contain asteroids, planets, stars or outposts']
}
```

