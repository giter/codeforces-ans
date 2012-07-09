<?php

function line($line){
	
	if(preg_match("/^(\s*)?([a-zA-Z][a-zA-Z0-9]*)?(\#[a-zA-Z0-9]+)?(\.[\.a-zA-Z0-9\-_]+)?(\#[a-zA-Z0-9]+)?(\(([^\)]+)\))?(.+)$/",$line,$m)){
		$e = array(
			"weight" => strlen($m[1]),
			"tag" => $m[2]?$m[2]: "div",
			"id" => $m[3]?$m[3]:$m[5],
			"classes" => trim(str_replace("."," ",$m[4])),
			"attrs" => $m[7],
			"text" => $m[8]
		);
		return $e;
	}

	return 0;
}

function lh($e){
	return "<${e['tag']} id='${e['id']}' class='${e['classes']}' ${e['attrs']}>${e['text']}";
}

function html($text){

	$str = "";
	$stack = array();

	$lines = split("\n",$text);
	foreach($lines as $line){
		
		$e = line(rtrim($line));

		if(count($stack) > 0 && $stack[count($stack)-1][1] < $e['weight']){
			$str .= "</".$stack[count($stack)-1][0].">";
			array_pop($stack);
		}

		$str .= lh($e);
		array_push($stack,array($e["id"],$e["weight"]));
	}

	while(count($stack) > 0){
		$v = array_pop($stack);
		$str .= "</".$v[count($stack)-1][0].">";
	}

	return $str;

}

echo html(<<<EOD
p.a
	abc
	p#b
		def
	p(style='margin-left:10px')
		hij

EOD
);

?>
