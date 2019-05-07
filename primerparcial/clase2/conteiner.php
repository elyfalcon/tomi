Producto.php
<?php

/**
 * 
 */
class Conteiner 
{
	private $_capacidad;
	private $_tamanio;
	public $ListaC=array();



 public function __construct($capacidad,$tamanio)
 {

 	$this->_capacidad=$capacidad;
 	$this->_tamanio=$tamanio;

 }

 public function  Mostrar()
 {

 	
 	echo $this->_tamanio."<br>";
 	echo $this->_capacidad."<br>";
 }

 

}



?>