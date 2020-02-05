class shipStats {
    constructor(){
        this.cargo = new Cargo();
        this.health = new Health();
        this.fuel = 0;
        this.weaponHardpoints = 0;
        this.modHardPoints = 0;
    }
}

class Cargo{
    constructor(){
        this.scrap = 0;
        this.supplies = 0;
        this.items = 0;
    }
}

class Health{
    constructor(){
        this.armor = 0;
        this.hull = 0;
        this.shields = 0;
    }
}