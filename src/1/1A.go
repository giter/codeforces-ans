package main

import "fmt"

func main(){
  

  n := uint64(0)
  m := uint64(0)
  a := uint64(0);

  fmt.Scanf("%d%d%d",&n,&m,&a);
  fmt.Println(((n+a-1)/a) *((m+a-1)/a));


}


