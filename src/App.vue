<template>
  <div id="app">
    <p> This is the App.vue</p>
    <router-view/>
  </div>
</template>
<script>
// componenets
import Login from './components/Login.vue'

export default {
  name: 'app',
  components: {
    Login
  },
  data () {
    return {
    }
  },
  created () {
    this.$router.push('/login');
  },
  methods: {
    init () {
    }
  }
}
</script>
<style lang="scss">
#app {
  font-family: monospace;
}
</style>
