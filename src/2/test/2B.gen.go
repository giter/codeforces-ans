package main 

import (
	"fmt"
	"math/rand"
)

func main(){

	fmt.Println(1000);
	for i:=0;i<1000;i++{
		for j:=0;j<1000;j++ {
			fmt.Print( rand.Int31()%100 + 1," ");
		}
		fmt.Println()
	}
}

