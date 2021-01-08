<template>
  <div id="app">
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
    //this.$router.push('/login');
  },
  methods: {
    init () {
    }
  }
}
</script>
<style lang="scss">
html, body {
  height: 100%;
  margin: 0;
}
#app {
  font-family: monospace;
  display: flex;
  justify-content: center;
  align-items: center;
  height: 100%;
}
</style>
