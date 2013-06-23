package main

import "fmt"
import "regexp"
import "bytes"

func itos(v int) string{

 var sb bytes.Buffer 

 for v > 0 {
  
  sb.WriteByte((byte)('A' + (v + 25) % 26))
  
  if (v % 26 == 0) {
    v -= 26
  }

  v /= 26
 }

 return sb.String()
}

func stoi(s string) int{

  v := int(0)
  m := int(1)

  for i := len(s) - 1; i >= 0; i-- {

    v += m * ((int)(s[i] - 'A') + 1)
    m *= 26;
  }

  return v;

}

func main(){

  re := regexp.MustCompile("(R\\d+C\\d+)|([A-Z]{2}\\d+)")
  ss := re.FindStringSubmatch("R23C11")

  if ss[1] != "" {
    fmt.Println(ss[1]);
  }

  if(ss[2] != ""){
  }

  fmt.Println(stoi("ZZ"))
  
}
