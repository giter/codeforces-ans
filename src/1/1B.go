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
 
 bs := sb.Bytes()
 i := 0
 j := len(bs) - 1

 for ; i < j ; {
	 bs[i],bs[j] =bs[j],bs[i]
	 i++
	 j--
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

	var n int
	fmt.Scanf("%d\n",&n)
	re := regexp.MustCompile("(R\\d+C\\d+)|(([A-Z]+)(\\d+))")

	for i := 0 ; i < n ; i ++ {

	  var k string
		fmt.Scanf("%s\n",&k)

		ss := re.FindStringSubmatch(k)
		
		if len(ss[1]) > 0  {
			var a,b int
			fmt.Sscanf(ss[1],"R%dC%d",&a,&b)
			fmt.Printf("%s%d\n",itos(b),a)
		}

		if len(ss[2]) > 0 {
			a := ss[3]
			var b int
			fmt.Sscanf(ss[4],"%d",&b)
			fmt.Printf("R%dC%d\n",b,stoi(a))
		}
	}

}
