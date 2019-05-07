<?php
class Producto
{
private $_id;
private $_nombre;
private $_importador;
private $_pais;
private $_kilos;
public $ListaP=array();


public function __construct($id,$nombre,$importador,$pais,$kilos)
{
 $this->_id=$id;
 $this->_nombre=$nombre;
 $this->_importador=$importador;
 $this->_pais=$pais;
 $this->_kilos=$kilos;

}

public function Mostrar()
{
	echo "Id producto: ".$this->_id."<br>";
	echo "Nombre : ".$this->_nombre."<br>";
	//echo "Importador: ".$this->_importador"<br>";
	echo "pais: ".$this->_pais."<br>";
	echo "Kilos: ".$this->_kilos."<br>";

}


}

