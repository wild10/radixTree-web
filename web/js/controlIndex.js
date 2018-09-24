

var c = document.getElementById("miCanvas");
var ctx = c.getContext("2d");
// graficar el circulo
ctx.beginPath();
var n = 0;
var array = [];

function insertData(){

  // variables globales
  var h_center,k_center, str ;
  // root center(h,k)
  h_center = 250;
  k_center = 75;

  var str = document.getElementById("txtInsert").value;  // para tamaño de letra <5
  var bool = -1;

  console.log("length: "+ array.length);
  array[array.length] = str;

  // para los hijos

  for(var i = 0; i < array.length; i++){
      if(i === 0){

        ctx.fillStyle = "#3498DB";
        ctx.strokeStyle = "black";
        ctx.font = "20px Georgia";
        ctx.lineWidth = 10;
        ctx.arc(h_center, k_center, 35, 0, 2 * Math.PI, false);
        ctx.fill();
        // escribir texto dentro del circulo
        ctx.beginPath();
        ctx.fillStyle = "black";
        // str = "casa";
        // llenar texto en cir
        ctx.fillText(str, (h_center - str.length*4), k_center+4);

      }else {

        if((i % 2) === 0){

          hijoDerecho(array[i],h_center +50,k_center +50);
        }else{
          hijoIzquierdo(array[i],h_center,k_center +50);
        }
      }
  }
  document.getElementById("txtInsert").value ="";
/*
  if(!n){
    ctx.arc(h_center, k_center, 35, 0, 2 * Math.PI, false);
    ctx.fill();
    // escribir texto dentro del circulo
    ctx.beginPath();
    ctx.fillStyle = "black";
    // str = "casa";
    // llenar texto en cir
    ctx.fillText(str, (h_center - str.length*4), k_center+4);
    bool = 0;
    n++;
  }else {
    if(bool === 0){

      hijoIzquierdo(str, h_center, k_center);
      bool = 1;
      n++;
    }else{
      hijoDerecho(str,h_center,k_center);
      bool = 0;
      n++;
    }

  }
  */

}

function hijoDerecho(str, h, k){
  // graficar el circulo
  ctx.beginPath();
  ctx.fillStyle = "#3498DB";
  ctx.strokeStyle = "black";
  ctx.font = "20px Georgia";
  ctx.lineWidth = 10;

  h_center = h+100;
  k_center = k+100;
  ctx.arc(h_center, k_center, 35, 0, 2 * Math.PI, false);
  ctx.fill();

  // escribir texto dentro del circulo
  ctx.beginPath();
  ctx.fillStyle = "black";
  var str = document.getElementById("txtInsert").value;  // para tamaño de letra <5

  // str = "casa";
  ctx.fillText(str, (h_center - str.length*4), k_center+4); // llenar texto en cir
}

function hijoIzquierdo(str, h, k){
  // graficar el circulo
  ctx.beginPath();
  ctx.fillStyle = "#3498DB";
  ctx.strokeStyle = "black";
  ctx.font = "20px Georgia";
  ctx.lineWidth = 10;

  h_center = h-100;
  k_center = k+100;
  ctx.arc(h_center, k_center, 35, 0, 2 * Math.PI, false);
  ctx.fill();

  // escribir texto dentro del circulo
  ctx.beginPath();
  ctx.fillStyle = "black";
  var str = document.getElementById("txtInsert").value;  // para tamaño de letra <5

  // str = "casa";
  ctx.fillText(str, (h_center - str.length*4), k_center+4); // llenar texto en cir
}

// dibujar nodo

function dibuja_Nodo(str, h, k){
  
  ctx.beginPath();
  ctx.fillStyle = "#3498DB";
  ctx.strokeStyle = "black";
  ctx.font = "12px Georgia";
  ctx.lineWidth = 10;

  h_center = h;
  k_center = k;
  ctx.arc(h_center, k_center, 25, 0, 2 * Math.PI, false);
  ctx.fill();

  // escribir texto dentro del circulo
  ctx.beginPath();
  ctx.fillStyle = "black";
  // var str = document.getElementById("txtInsert").value;  // para tamaño de letra <5

  // str = "casa";
  ctx.fillText(str, (h_center - str.length*2), k_center+2);
}

// ctx.beginPath();
// ctx.arc(100, 75, 40, 0, 2* Math.PI);
// ctx.stroke();


/*
ctx.arc(h_center+ 100, k_center+ 100, 35, 0, 2 * Math.PI, false);
ctx.fill();
*/

// ctx.fill();

/**
 * funcion get para el recibir datos
 */
function handleClick(event){

    //obtener el texto
    var str = document.getElementById("txtInsert").value;

    console.log("input: "+str);

    var http = new XMLHttpRequest();
    var url = 'http://localhost:8091/radix';
    var params = 'orem=ipsum&name=binny';
    http.open('GET', url, true);

    http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

    http.onreadystatechange = function() {
        if(http.readyState == 4 && http.status == 200) {
            console.log(http.responseText);
            alert(http.responseText);

        }
    }
    http.send(params);
}

function enviar(){

  //obtener el texto
  var str = document.getElementById("txtInsert").value;

  console.log("input: "+str);

  var http = new XMLHttpRequest();
  var url = 'http://localhost:8091/radix/getOptions?word='+str.toUpperCase();
  var params = 'orem=ipsum&name=binny';
  http.open('GET', url, true);

  http.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

  http.onreadystatechange = function() {
      if(http.readyState == 4 && http.status == 200) {
          // console.log("---->>"+http.responseText);
          var arr = JSON.parse(http.responseText)["tree"];
          // alert(http.responseText);
           var h = 50; 
           var k = 50;

          for(var i = 0; i < arr.length; i++){
            console.log(arr[i].valor);
            dibuja_Nodo(arr[i].valor, h,k*(i+1));
          }

      }
  }
  http.send(params);

}

/**
 * funcion POST para enviar data al servidor
 */
function envioPost(){

 var http = new XMLHttpRequest();
 var url = 'http://localhost:8091/radix/arrays';

 http.open("POST", url, true);

 http.setRequestHeader('Content-Type', 'application/json');

 // http.onreadystatechange = function() {//Call a function when the state changes.
 //     if(http.readyState == 4 && http.status == 200) {
 //         alert(http.responseText);
 //     }
 // }

 http.send(JSON.stringify({
	"points": [{ "x": 5 , "y":6} ]
 }));

 console.log("here"+http.responseText);

}
