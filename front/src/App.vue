<template>
  <div id="app">
    <Map></Map>
    <div class="right">
      <router-view/>
    </div>
  </div>
</template>

<script>
  import Map from "./components/Map/index"
  import Order from "./components/Order/index"
export default {
  name: 'App',
  components: {
    Map,
    Order
  }

}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
