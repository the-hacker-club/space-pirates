export class ShipStats {
    constructor(){
        this.cargo = new Cargo();
        this.health = new Health();
        this.fuel = 111;
        this.weaponHardpoints = 222;
        this.modHardPoints = 333;
        this.scrap = 444;
        this.supplies = 555;
        this.items = 666;
        this.armor = 777;
        this.hull = 888;
        this.shields = 999;
    }
}

class Cargo{
    constructor(){
        this.scrap = 444;
        this.supplies = 555;
        this.items = 666;
    }
}

class Health{
    constructor(){
        this.armor = 777;
        this.hull = 888;
        this.shields = 999;
    }
}