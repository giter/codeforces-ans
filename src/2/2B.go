package main

import "fmt"
import "os"
import "bufio"
import "container/list"

var n = int(0)
var z = [1000][1000][2]int{}

func min(a int,b int) int{
	if a>b { return b }
	return a
}

func max(a int,b int) int {
	if a > b { return a }
	return b
}

func abs(a int) int{
	if a > 0 { return a }
	return -a
}

func p(a int) (int,int) {

	t := 0
	f := 0

	if a == 0 { return t,f }

	for ;a%5==0;a/=5 {
		f++
	}

	for ;a%2==0;a/=2 {
		t++
	}

	return t,f
}


func isDigit(b byte) bool{
	return b >= '0' && b <= '9'
}

func readLine() error{
	var err error
	_buf,err = _in.ReadBytes('\n')
	_lb = len(_buf)
	_pos = 0
	return err
}

func nextInt() (int,error){

	for digit:=false;!digit; {

		if _pos >= _lb {
			err := readLine()
			if err != nil {
				return -1,err
			}
		}

		for ; _pos < _lb && !digit ; _pos++ {

			digit = isDigit(_buf[_pos])

			if digit {
				break
			}
		}

	}

	r := 0

	for ; _pos < _lb && isDigit(_buf[_pos]) ; {
		r = r*10 + int(_buf[_pos]) - '0'
		_pos++
	}


	return r,nil
}

var (
	_in = bufio.NewReader(os.Stdin)
	_buf []byte
	_lb = int(-1)
	_pos = int(0)
)


func main(){


	n,_ := nextInt()


	v := 0
	zx := -1
	zy := -1

	for i:=0;i<n;i++ {
		for j:=0;j<n;j++ {

			v,_ = nextInt()

			z[i][j][0],z[i][j][1] = p(v)

			if(v == 0){
				zx = i
				zy = j
			}
		}
	}


	for i:=1;i<n;i++{
		z[i][0][0] += z[i-1][0][0]
		z[i][0][1] += z[i-1][0][1]
		z[0][i][0] += z[0][i-1][0]
		z[0][i][1] += z[0][i-1][1]
	}

	for i:=1;i<n;i++ {
		for j:=1;j<n;j++ {
			for k:=0;k<2;k++ {
				z[i][j][k] += min(z[i][j-1][k],z[i-1][j][k])
			}
		}
	}

	var ans = min(z[n-1][n-1][0],z[n-1][n-1][1])


	if zx!=-1 && zy!=-1 && ans > 1 {

		fmt.Println(1)

		x := 0
		y := 0

		for x < zx {
			fmt.Print("D")
			x++
		}

		for y < zy {
			fmt.Print("R")
			y++
		}

		for x < n-1 {
			fmt.Print("D")
			x++
		}

		for y < n-1 {
			fmt.Print("R")
			y++
		}

		fmt.Println()

	} else {

		fmt.Println(ans)

		var k int
		x := n-1
		y := n-1
		xs := list.New()

		if(z[n-1][n-1][0] < z[n-1][n-1][1]) {
			k = 0
		}else{
			k = 1
		}

		for !(x == 0 && y == 0 ) {

			if x==0 {
				xs.PushBack("R")
				y--
			}else if y==0 {
				xs.PushBack("D")
				x--
			}else {

				if z[x-1][y][k] < z[x][y-1][k]{
					xs.PushBack("D")
					x--
				}else{
					xs.PushBack("R")
					y--
				}
			}

		}

		for e:=xs.Back();e!=nil;e=e.Prev(){
			fmt.Print(e.Value.(string))
		}

		fmt.Println()
	}

}
