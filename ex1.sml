(*programma tis askhshs 1. *)
(*Complexity= O(n)*)        
fun skitrip file =

let

    fun next_int input =
    	Option.valOf (TextIO.scanStream (Int.scan StringCvt.DEC) input)

    (*kurio meros tou programmatos*)

    fun make_max  ([],max)= []
      | make_max (h::t,max)= if h>max then h::make_max(t,h) else max::make_max (t,max)

    fun max (a,b) = if (a>b) then  a else b

    (*h sunarthsh auth ulopoiei ton algorithmo*)
    fun check ([],li,ans,_,_)= ans 
      | check (li,[],ans,_,_)= ans
      | check (lmin,lmax,ans,pntr_min,pntr_max)= if (hd(lmax)>=hd(lmin)) then check(lmin,tl(lmax),max (ans,pntr_max-pntr_min),pntr_min,pntr_max+1) else check(tl(lmin),lmax,ans,pntr_min+1,pntr_max)  	

    (*telos kuriou merous edw diavazoume arithmous kai kaloume to apo panw meros*)
    val stream = TextIO.openIn file
    val n = next_int stream (* diavazoume ton aritmo twn stasewn*)
    val _ = TextIO.inputLine stream

    (*kataskeuazoume mia lista me tous arithmous apo to arxeio eisodou kai kaloume to kurio meros ekteleshs*)	
    fun make_list (stream,x,li)= if x>0 then make_list(stream,x-1,(next_int stream)::li) else check(rev(li),rev(make_max(li,hd(li))),0,0,0)	

 in
 	make_list(stream,n,[])
end          