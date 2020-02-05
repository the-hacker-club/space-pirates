
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
    }
}
