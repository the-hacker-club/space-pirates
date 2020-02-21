
class Attributes {
    constructor() {
        this.STR = 380;
        this.DEX = 300;
        this.CON = -234;
        this.INT = 30;
        this.WIS = 39;
        this.CHA = 88;
        
    }

    get_STR() {
        return this.STR;
    }

    set_STR(value) {
        this.STR = value;
    }
}

export class Character {
    constructor(name) {
        console.log("hello?");
        this.attributes = new Attributes();
        this.occupation = "Bum";
        this.name = name;
        this.age = 34;
        this.money = 10000;
        this.scrap = 111;
        this.fuel = 222;
        this.supplies = 333;
        this.reputation = "good";
        this.cargo = 444;
    }
}
