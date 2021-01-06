<template>
  <div id="login">
    <div class="logo"/>
    <p id="message" v-show="false"/>
    <div class="container">
      <div class="inputContainer">
        <div class="labelContainer">
          <label for="emailInput">email: </label>
        </div>
        <input id="emailInput" label="email" v-model="email">
      </div>
      <div class="inputContainer">
        <div class="labelContainer">
          <label for="passwordInput">password: </label>
        </div>
        <input id="passwordInput" type="password" v-model="password">
      </div>
      <div class="inputContainer" v-if="signup" display="none">
        <div class="labelContainer">
          <label for="confirmPassword">confirm password: </label>
        </div>
        <input id="confirmPassword" type="password" v-model="confirmPassword">
      </div>
      <div class="buttonContainer">
        <button>Login</button>
        <button v-on:click="signup=!signup">Signup</button>
      </div>
    </div>
  </div>
</template>

<script>

export default {
  name: 'login',
  data () {
    return {
      email: '',
      password: '',
      passwordConfirm: '',
      signup: false
    }
  },
  created () {
  },
  methods: {
    login () {
    },
    signUp () {
    }
  }
}
</script>

<style>

html {
  background: black;
  font-family: monospace;
}

#login {
  text-align: center;
  display: flex;
  align-items: center;
  flex-direction: column;
}

.logo {
  height: 150px;
  width: 200px;
  margin-top: 60px;
  background-image: url("./assets/jollyroger.png");
  background-size: contain;
  background-repeat: no-repeat;
}

.inputContainer {
  display: flex;
  margin: 10px;
  align-items: center;
  align-self: center;
  padding: 0px 56px;
}

input {
  border-color: rgb(0,255,0);
  background-color: #00000000;
  color: rgb(0,255,0);
}
input:focus {
  outline: none !important;
  outline-offset: 0px !important;
}
textarea:focus {
  outline: none !important;
  outline-offset: 0px !important;
}

.container {
  display: flex;
  align-items: center;
  flex-direction: column;
  width: 500px;
}

.buttonContainer {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  width: 100%;
  margin: 10px;
}

button {
  border-color: rgb(0,255,0);
  background-color: #00000000;
  color: rgb(0,255,0);
  width: 100px;
  margin: 5px;
}

label {
  color: rgb(0,255,0);
  padding: 0px 10px;
  width: 180px;
}
.labelContainer {
  text-align: end;
  width: 180px;
}
</style>
