<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
    <HelloWorld :msg="greeting"/>
    <p>Player attributes: {{ playerstats }} </p>

    <div class="Flex-Container">
      <div><button type="button">Hull: {{ ShipHull }}</button></div>
      <button type="button">Armor: {{ ShipArmor }}</button>
      <button type="button">Shields: {{ ShipShields }}</button>
      <button type="button">Scrap: {{ ShipScrap }}</button>
    </div>
    <div id="WebGLBoxPH">
       <Screen/>
    </div>
    <div class="Flex-Container">
      <button type="button">Supplies: {{ ShipSupply }}</button>
      <button type="button">Items: {{ ShipItems }}</button>
      <button type="button">Fuel: {{ ShipFuel }}</button>
      <button type="button">Hardpoints: {{ ShipHardPoints }}</button>
    </div>

  </div>
</template>

<script>
// componenets
import HelloWorld from './components/HelloWorld.vue'
import Screen from './components/Screen.vue'

// models
import msg from './models/Message.js'
import {Character} from './models/Player.js'
import {ShipStats} from './models/Ship.js'

export default {
  name: 'app',
  components: {
    HelloWorld,
    Screen
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
      ShipHardPoints: ''
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
#WebGLBoxPH{
  width: 50%;
  max-width: 600px;
  min-width: 500px;
  height: 400px;
  background-color: black;
  margin: auto;
}
.Flex-Container {
  display: flex;
  width: 50%;
  margin: auto;
  align-items: center;
  justify-content: center;
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
