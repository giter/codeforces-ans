<?php

function line($line){
	if(preg_match("/^(\s*)(h1|h2|h3|h4|h5|h6|div|p|blockquote|a|ul|li|ol)?(#[a-zA-Z0-9\-_]+)?(\.[\.a-zA-Z0-9\-_]+)?(#[a-zA-Z0-9\-_]+)?(\(([^\)]+)\))?/",$line,$m)){
		
		$e = array(
			"weight" => strlen($m[1]),
			"tag" => $m[2]?$m[2]: "div",
			"id" => trim(str_replace("#","",$m[3]?$m[3]:$m[5])),
			"classes" => trim(str_replace("."," ",$m[4])),
			"attrs" => $m[7]
		);

		$e['text'] = ltrim(substr($line,strlen($m[0])));

		return $e;
	}else{
		return array("text"=>$line);
	}
}

function lh($e){
	if($e['tag'])
		return "<${e['tag']}".($e['id']?" id='${e['id']}'":"").($e['classes']?" class='${e['classes']}'":"").($e['attrs']?" ${e['attrs']}":"").">${e['text']}";
	else
		return $e['text'];
}

function html($text){

	$str = "";
	$stack = array();

	$lines = split("\n",$text);
	foreach($lines as $line){
		
		$e = line(rtrim($line));

		if(isset($e['tag'])){
			if(count($stack) && $stack[count($stack)-1][1] < $e['weight']){
				$str .= "</".$stack[count($stack)-1][0].">";
				array_pop($stack);
			}
		}

		$str .= lh($e);
		
		if($e['tag'])
			array_push($stack,array($e["tag"],$e["weight"]));
	}

	while(count($stack)){
		$v = array_pop($stack);
		$str .= "</".$v[0].">";
	}

	return $str;

}

while($l = readline()){
	echo html($l);
}

?>
