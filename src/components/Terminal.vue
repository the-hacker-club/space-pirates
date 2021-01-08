<template>
  <div id="Terminal">
    <div class="terminal">
      <table>
        <tr>
          <td rowspan="2" />
          <td rowspan="8" colspan="4">
            <div id="WebGLBoxPH">
              <Screen/>
            </div>
          </td>
          <td rowspan="2" />
        </tr>
        <tr>
        </td>
        <tr>
          <td><router-link to="/">View</router-link></td>
          <td>View</td>
        </tr>
        <tr>
          <td><router-link to="/">Navigation</router-link></td>
          <td>Navigation</td>
        </tr>
        <tr>
          <td><router-link to="/">Market</router-link></td>
          <td>Market</td>
        </tr>
        <tr>
          <td><router-link to="/">Crew</router-link></td>
          <td>Crew</td>
        </tr>
        <tr>
          <td><router-link to="/">Ship</router-link></td>
          <td>Ship</td>
        </tr>
        <tr>
          <td><router-link to="/">Inventory</router-link></td>
          <td>Inventory</td>
        </tr>
        <tr>
          <td></td>
          <td>Navigation</td>
          <td>Land</td>
          <td>Scan Area</td>
          <td>Repairs</td>
          <td></td>
        </tr>
        <tr>
          <td></td>
          <td>Navigation</td>
          <td>Land</td>
          <td>Scan Area</td>
          <td>Repairs</td>
          <td></td>
        </tr>
      </table>
      </div>
    </div>
  </div>
</template>

<script>
// componenets
import HelloWorld from './HelloWorld.vue'
import Screen from './Screen.vue'

// models
import msg from '../models/Message.js'
import {Character} from '../models/Player.js'
import {ShipStats} from '../models/Ship.js'
import {mapState} from 'vuex'


export default {
  name: 'terminal',
  components: {
    HelloWorld,
    Screen
  },
  computed: mapState({
    // arrow functions can make the code very succinct!
    email: state => state.email,

    // passing the string value 'email' is same as `state => state.email`
    emailAlias: 'email',
  }),
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
    console.log(this.$store.state.email);
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

html {
  background: black;
  color: white;
}

table,  td{
  border-collapse: collapse;
  border-style: ridge;
}

td {
  text-align: center;
  width: 110px;
  white-space: pre;
}

tr {
  height: 40px;
}

p {
  margin: 3px;
}

/* unvisited link */
a:link {
  color: #0066ff;
}

/* visited link */
a:visited {
  color: #0066ff;
}

/* mouse over link */
a:hover {
  color: #00ccff;
}

/* selected link */
a:active {
  color: #00ccff;
}

.column {
  min-width: 120px;
}

.terminal{
  display: flex;
  align-items: center;
  justify-content: center;
}
#WebGLBoxPH{
  width: 460px;
  height: 320px;
  background-color: black;
}
</style>
