package main

import "fmt"

func main(){

  m := make(map[string]int,1000)
  ln := make([]string,1000)
  ls := make([]int,1000)
	
  var n string
  var s,t int
  fmt.Scanln(&t)

    ms := int(-2000*1000) //max score

  for i:=0 ; i<t ; i++ {
    
    fmt.Scanln(&n,&s)

    ln[i] = n
    ls[i] = s

    m[n] += s
  }

  for _,v := range m {
    if v>ms { ms = v }
  }

  k := make(map[string]int,1000)

  for i:=0;i<t;i++ {

    n = ln[i] 
    s = ls[i]

    k[n] += s

    if k[n] >= ms && m[n] == ms {
      fmt.Println(n)
      return;
    }

  }

}
