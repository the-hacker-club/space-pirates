<template>
  <div id="screen" />
</template>

<script>
import * as THREE from 'three';

export default {
  name: 'Screen',
  props: {
    msg: String
  },
  data() {
    return {
    camera: null,
    scene: null,
    renderer: null,
    geometry: null,
    material: null,
    mesh: null
    }
  },
  mounted() {
    this.init();
    this.animate();
  },
  methods: {
    init: function() {
        let container = document.getElementById('screen');
        this.camera = new THREE.PerspectiveCamera( 70, window.innerWidth / window.innerHeight, 0.01, 10 );
        this.camera.position.z = 1;

        this.scene = new THREE.Scene();

        this.geometry = new THREE.BoxGeometry( 0.2, 0.2, 0.2 );
        this.material = new THREE.MeshNormalMaterial();

        this.mesh = new THREE.Mesh( this.geometry, this.material );
        this.scene.add( this.mesh );

        this.renderer = new THREE.WebGLRenderer( { antialias: true } );
        this.renderer.setSize( container.clientWidth, container.clientHeight );
        //this.renderer.setSize(container.width(), container.height());
        container.appendChild( this.renderer.domElement );
    },
    resizeCanvasToDisplaySize: function() {
      const canvas = this.renderer.domElement;
      // look up the size the canvas is being displayed
      const width = canvas.clientWidth;
      const height = canvas.clientHeight;
      console.log("width: " + canvas.width + ", height: " + canvas.height);
      //console.log("width: " + width + ", height: " + height);

      // adjust displayBuffer size to match
      if (canvas.width !== width || canvas.height !== height) {
        // you must pass false here or three.js sadly fights the browser
        this.renderer.setSize(width, height, false);
        this.camera.aspect = width / height;
        this.camera.updateProjectionMatrix();

        // update any render target sizes here
      }
    },
    animate: function() {
        requestAnimationFrame( this.animate );

        //this.resizeCanvasToDisplaySize();

        this.mesh.rotation.x += 0.01;
        this.mesh.rotation.y += 0.02;

        this.renderer.render( this.scene, this.camera );
    }
  }
}
</script>

<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
#screen {
width:100%;
height:100%;
}
</style>
