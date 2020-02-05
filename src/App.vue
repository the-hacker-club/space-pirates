<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
    <HelloWorld :msg="greeting"/>
    <p>Player attributes: {{ playerstats }} </p>
  </div>
</template>

<script>
// componenets
import HelloWorld from './components/HelloWorld.vue'

// models
import msg from './models/Message.js'
import {Character} from './models/Player.js'

export default {
  name: 'app',
  components: {
    HelloWorld
  },
  data () {
    return {
      greeting: '',
      playerstats: ''
    }
  },
  created () {
    this.getMsg()
    console.log('oh my!');

    var player = new Character("Joe");
    //player.attributes.set_STR(10);

    this.playerstats = player.attributes.get_STR();

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
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
