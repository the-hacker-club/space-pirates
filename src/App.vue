<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
    <HelloWorld :msg="greeting"/>
    <p>Player attributes: {{ playerstats }} </p>

    <div class="Main-Container">
      <div class="Column">
        <button type="button" class="sideButtons">Captain: {{ playerName }}</button>
        <button type="button" class="sideButtons">Age: {{ playerAge }}</button>
        <button type="button" class="sideButtons">Scrap: {{ playerScrap }}</button>
        <button type="button" class="sideButtons">Fuel: {{ playerFuel }}/{{ShipFuel}}</button>
        <button type="button" class="sideButtons">Supplies: {{ playerSupply }}</button>
        <button type="button" class="sideButtons">Credits: {{ playerMoney }}</button>
        <button type="button" class="sideButtons">Reputation: {{ playerRep }}</button>
        <button type="button" class="sideButtons">Cargo: {{ playerCargo }}</button>
     
      </div>
      <canvas id="WebGLBoxPH"></canvas>
      <div class="Column">
        <button type="button" class="sideButtons">Captain: {{ ShipSupply }}</button>
        <button type="button" class="sideButtons">Age: {{ ShipItems }}</button>
        <button type="button" class="sideButtons">Scrap: {{ ShipFuel }}</button>
        <button type="button" class="sideButtons">Fuel: {{ ShipHardPoints }}</button>
        <button type="button" class="sideButtons">Supplies: {{ ShipSupply }}</button>
        <button type="button" class="sideButtons">Credits: {{ ShipItems }}</button>
        <button type="button" class="sideButtons">Reputation: {{ ShipFuel }}</button>
        <button type="button" class="sideButtons">Cargo: {{ ShipHardPoints }}</button>
     </div>
      </div>
      <div class="Flex-Container">
        <button type="button" class="bottomButtons">Supplies: {{ ShipSupply }}</button>
        <button type="button" class="bottomButtons">Items: {{ ShipItems }}</button>
        <button type="button" class="bottomButtons">Fuel: {{ ShipFuel }}</button>
        <button type="button" class="bottomButtons">Hardpoints: {{ ShipHardPoints }}</button>
      </div>
      <div class="Flex-Container">
        <button type="button" class="bottomButtons">Hull: {{ ShipHull }}</button>
        <button type="button" class="bottomButtons">Armor: {{ ShipArmor }}</button>
        <button type="button" class="bottomButtons">Shields: {{ ShipShields }}</button>
        <button type="button" class="bottomButtons">Scrap: {{ ShipScrap }}</button>
      </div>
      
    
  </div>
</template>

<script>
// componenets
import HelloWorld from './components/HelloWorld.vue'

// models
import msg from './models/Message.js'
import {Character} from './models/Player.js'
import {ShipStats} from './models/Ship.js'

export default {
  name: 'app',
  components: {
    HelloWorld
  },
  data () {
    return {
      greeting: '',
      playerstats: '',
      ShipHull: '',
      ShipArmor: '',
      ShipShields: '',
      ShipScrap: '',
      ShipSupply: '',
      ShipItems: '',
      ShipFuel: '',
      ShipHardPoints: '',
      playerName: '',
      playerAge: '',
      playerScrap: '',
      playerFuel: '',
      playerSupply: '',
      playerMoney: '',
      playerRep: '',
      playerCargo: ''
    }
  },
  created () {
    this.getMsg()
    console.log('oh my!');

    var player = new Character("Joe");
    var ship = new ShipStats();
    //player.attributes.set_STR(10);

    this.playerstats = player.attributes.get_STR();
    this.ShipHull = ship.hull;
    this.ShipArmor = ship.armor;
    this.ShipShields = ship.shields;
    this.ShipScrap = ship.scrap;
    this.ShipSupply = ship.supplies;
    this.ShipItems = ship.items;
    this.ShipFuel = ship.fuel;
    this.ShipHardPoints = ship.weaponHardpoints;
    this.playerName = player.name;
    this.playerAge = player.age;
    this.playerScrap = player.scrap;
    this.playerFuel = player.fuel;
    this.playerSupply = player.supplies;
    this.playerMoney = player.money;
    this.playerRep = player.reputation;
    this.playerCargo = player.cargo;
     
    console.log('created new character:');
    console.log(player);
  },
  methods: {
    getMsg () {
      return msg.getInitMsg()
        .then(msg => this.greeting = msg)
    }
  }
}
</script>

<style>

.Main-Container{
  display: flex;
  
  align-items: center;
  justify-content: center;
}
.Column {
  
  height: 400px;
  width: 200px;
  
  background-color: grey;
}
#WebGLBoxPH{
  width: 500px;
  
  height: 400px;
  background-color: black;
  
}
.Flex-Container {
  display: flex;
  
  
  align-items: center;
  justify-content: center;
}
.sideButtons {
  height: 12.5%;
  width: 100%;
  font-size: 18px;
  
}
.bottomButtons{
  height: 50px;
  width: 200px;
  font-size: 18px;
}
button {
  
  background-color: black;
  border-color: blue;
  color: blue;
  padding: 5px;
}
button:hover{
  background-color: orange;
}
button:focus{
  background-color: red;
}
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
