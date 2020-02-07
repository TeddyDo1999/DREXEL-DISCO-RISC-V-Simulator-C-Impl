Electrical and Computer Engineering Department	      	     	     	       
       	    		       	   	 	     	       	    	   
By Dr Anup Das	    		      	    	      	    	  	 
      		 	  	     	       	      	   		       
       	    	     	  	     	   	     	      	   	  
ECEC 355: Practice Midterm       			   		      
	       	  	   	      	    	     	     	  	   
Winter 2020      	      	 	      	    	     	     	  
      	       	      	     	       	  	  	   	      	       
Hanh Do Phung     	      	       	 	       	 	      	     
   	      	 	  	  	   	   	  	   	   
  	 	  	   	       	     			   	 
1. Consider the following RISC-V loop: 	      		 	      	       
	      	 	   		      	      	      	  	       
(i) LOOP: beq x6, xO,DONE    	 	      	     	    	       	   
 	 	  	     	     	    	     		   	    
(ii) addi x6, x6,-1       	  	     	 	   	  	   
    	       	 	    	       	     	     	  	       	      
(iii) addi x5, x5,2       	  		       	      	       	       
       	  	 	   	    	     	    	      	   	      
(iv) s||i x7, x5,1   	 		    		 	      	     
  		       	      	 	    	  	       		       
(v) jal x0, LOOP      	    		    	   		    	     
     	  	      	   	   	       	  	 	   	    
(vi) DONE: some-other-instruction   	      	    			     
   	       	       	       	       	     	 	    	      	       
Assume that the register x6 is initialized to the value 5, and x5 and x7 to the value 0.
 	   		  	       	       	      	     	   	     
Fill the table below    	    	   	    	      	       
	       	      		 	     	       	       		
	  	   	  	       	   	      	  	   	     
  	  	    	    	       	      	      	      	    	     
   	    	    	 	 	     	    	    	      	       
   		    	      	     	    	     	     	 	     
      	      	     	    	  	     	       	 	 	      
      	     	  	     	   	    	    	   	   
	    	      	     	     	 	       	 	     	    
	      	  	     	    	      	      	      	       	    
  	    	    	   	     	   		  	     
	      	    	      		      	 		    	  
Final value of x5 at the end of execution 10 2 credit      	     	       
   		 	 	   	    		  	    	      
     	 	 		      	   	   	 	   	 
Final value of x7 at the end of execution 20 2 credit    	     
	      	 	   		   	       	 	     	      
       	    		     	    		 	  	  	       
Total number of instructions executed 26 1 credit  	    	  	    
      	       	   	      		  	 	       	      
	    	   	    	      	   	     	    	  	     
      	 	  	    	     	     	    	  	 	     
	     	      	  	      	 	  	 	   	      
    	       	 	 		    	    	     	 
	      	      	    	       	     	     	      	     	    
    	    	    	     	   	  	 	      	       	       
      	     	       	    	       	       	    	       		      
      	    	 			  	     		     	     
2. I have the following instruction: addi x6, x7, 9. Represent this instruction in
    	   	    	     	  		  	    	 	       
hexadecimal format filling all unused fields with 0’s (2 credit).  	 
    	    	       	   	       	      	  		       	 
Ans: 0x00938313      			 	    	   	     	      
   	 	    	       	 	     	  		     	       
    	     		      	 	 	 	     	  	     
  	      	   		 	      	   	   	    	    
3. I have an array (A) of unknown size, with each array element represented using 8 bits.
    	    	     	       	    	    	    		       	   
The base address of this array is O and the array elements are initialized as [0, 1, 2, 3,
     	 	      	       		 	   	 	      	  
4,5,...]. In other words, A(O) = O, A(1)= 1, A(2) = 2, and so on.   	 
     	  	     	       	       			 	       	     
     	  	       			      		  	     	   
      	       	  	 	   	 	       	  		     
  	     	     	       	    	  	       	       	       	 
I have stored register x9 = 1. I have the following RISC-V codes:      	  
 	     	     	  	    	     	     	       	     	     
 	       	    	   		   	       	       	 	       
lb x7, 1(x9)   	    	   	     		   	       	    	       
       	      	       	      	      	 	 		    	 
lb x8, O(x9)      		       	    		     	      	   
      	     		 	 	     	    	 	     	      
addi x9, x7, 1     	    		  	      	     	    	    
  	       	      	      	 		 	      		 
sb x7, 2(x9)     	  	 	       	      		 	 
       	      	       	  	 	     	 	    	   	     
subi x9, x9,3      		      	  	       		      	      
   	     	 	 		      		    		 
sb x8, O(x9)	   	    		  	  	       	       	  
	       	  	     	  	 		      	      	    
    	   	       	   	   		   	      	      	  
What is the new content of the array A after this RISC-V code executes? (3 credits)
    	    	       		     	      	 	     	    
	  	       	       	  	   	 	  	  	     
       	    	     	    	 	       	       		      	      
A(O)    A(l)    A(Z)    A(3)    A(4)    A(5)    A(6)   		       	  
  	  	 		      	       	 	    	   	      
 	       	 	       	     	    	       	   	      	       
      	 	    	       	  	  	 	   	      	   
l       l       2       3       4       2       6    	 	      	      
      		 	      	  	       	       	 		      
	     	     	  	  			   	    	   
      	 	     	   	      		 	   	   
	  	 	   		 	    	       	   	       
	      	      	     	  	      	   	    	    	     
 	    	  	  	      	      	  	       	   	       
  	 		   	      	  	  	      		      
     		   	   	 	      	   	    	      	 
    	 	    	       	    	    	       	 	     	  
    	       	  	      	    	     	     	   	   	    
 	      	   		  	       	       	      	   	   
     	       	    	     	      	  	     	     	       	       
  	     	       	   	  		     	     	     	   
  	       	   	    	   	      	    			  
  	      	 	 	     	   		 	 	       
    	  		   	    	 	       	  		       
    		     	       	    	  	       	   	       	      
  	 	  	       	     	   	       	   	      	      
     	     		      	       	     	      	  		       
4. I have the following information available to me for my program which has 3 sets of
   	   				       	 	      		    
instructions. 	       	  	      	   			       
	       	  	   	   	    	    		    	 
    	 	     	      	      	      	 	      	   
		      	      	    	 	   	  	    	     
CPU Class A B C D 	  		   		    	      
	    	   	    	   	       	    	   	       	     
CPI for the class 1 1.5 2 3  	     	 	      	    	    	      
       	 	   	     	      			   	     	   
Instruction Set 1 3O 4O 20 10       	  		  	       
	    	   	  	    	     	     	    	    	     
Instruction Set 2 10 4O 4O 10       	       	   	   	     	 
	     	    		  	      	     		       	       
Instruction Set 3 80 O O 20   	 	    	     	    	       	 
   	  	    	      		      	     	      	 	 
Answer the following      	 	       	     			       
    	       	 	  	 	      	      	       	    	      
Average CPI of Instruction Set 1 1.6 1 credit   		    	   
   		    	      	   	 	  	   	  	      
Average CPI of Instruction Set 2 1.8 1 credit     	   	 	     
      	      	      
Average CPI of Instruction Set 3 1.4 1 credit

Average CPI of the overall program 1.6 2 credit


























