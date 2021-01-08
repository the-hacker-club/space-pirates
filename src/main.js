import Vue from 'vue'
import App from './App.vue'
//import Login from './components/Login.vue'
import Terminal from './components/Terminal.vue'
import VueRouter from 'vue-router'
import 'es6-promise/auto'
import Vuex from 'vuex'

Vue.config.productionTip = false
// 0. If using a module system (e.g. via vue-cli), import Vue and VueRouter
// and then call `Vue.use(VueRouter)`.
Vue.use(VueRouter)
Vue.use(Vuex)

const store = new Vuex.Store({
  state: {
    email: ''
  },
  mutations: {
    login (state, email) {
      state.email = email
    }
  }
})

// 1. Define route components.
// These can be imported from other files
const Login = () => import('./components/Login.vue')

// 2. Define some routes
// Each route should map to a component. The "component" can
// either be an actual component constructor created via
// `Vue.extend()`, or just a component options object.
// We'll talk about nested routes later.
const routes = [
  { path: '/', redirect: '/login' },
  { path: '/login', component: Login, props: true },
  { name: 'terminal', path: '/terminal', component: Terminal, props: true },

]

// 3. Create the router instance and pass the `routes` option
// You can pass in additional options here, but let's
// keep it simple for now.
const router = new VueRouter({
  routes // short for `routes: routes`
})
new Vue({
  router,
  store: store,
  render: h => h(App)
}).$mount('#app')
