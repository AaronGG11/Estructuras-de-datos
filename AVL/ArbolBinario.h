  
 t y p e d e f   s t r u c t   N o d o { 
 	 E l e m   r a i z ; 
 	 s t r u c t   N o d o   *   i z q u i e r d o ; 
 	 s t r u c t   N o d o   *   d e r e c h o ;   
 }   *   A r B i n ; 
 
 A r B i n   v a c i o ( ) { 
 	 r e t u r n   N U L L ; 
 } 
 
 A r B i n   c o n s ( E l e m   r ,   A r B i n   i ,   A r B i n   d ) { 
 	 A r B i n     t e m p o r a l   =   ( A r B i n ) m a l l o c ( s i z e o f ( s t r u c t   N o d o ) ) ; 
 	 t e m p o r a l   - >   r a i z   =   r   ; 
 	 t e m p o r a l   - >   i z q u i e r d o   =   i ; 
 	 t e m p o r a l   - >   d e r e c h o   =   d ; 
 	 r e t u r n   t e m p o r a l ; 
 } 
 
 i n t   e s V a c i o ( A r B i n   a ) { 
 	 r e t u r n   a   = =   v a c i o ( ) ; 
 } 
 
 E l e m   r a i z ( A r B i n   a ) { 
 	 r e t u r n   a   - >   r a i z ; 
 } 
 
 A r B i n   i z q ( A r B i n   a ) { 
 	 r e t u r n   a   - >   i z q u i e r d o ; 
 } 
 
 A r B i n   d e r ( A r B i n   a ) { 
 	 r e t u r n   a   - >   d e r e c h o ; 
 } 
 
 i n t   n u m E l e m ( A r B i n   a ) { 
 	 i f ( e s V a c i o ( a ) ) 
 	 	 r e t u r n   0 ; 
 	 e l s e { 
 	 	 r e t u r n   1   +   n u m E l e m ( i z q ( a ) )   +   n u m E l e m ( d e r ( a ) ) ; 
 	 } 
 } 
 
 / /   F o r m a s   d e   r e c o r r e r   u n   a r b o l   
 v o i d   i n O r d ( A r B i n   a ) {   / /   i z q u i e r d o ,   r a i z ,   d e r e c h o 
 	 i f ( ! e s V a c i o ( a ) ) { 
 	 	 i n O r d ( i z q ( a ) ) ; 
 	 	 i m p E l e m ( r a i z ( a ) ) ; 
 	 	 i n O r d ( d e r ( a ) ) ; 
 	 } 
 } 
 
 v o i d   p r e O r d ( A r B i n   a ) {   / /   r a i z ,   i z q u i e r d o ,   d e r e c h o 
 	 i f ( ! e s V a c i o ( a ) ) { 
 	 	 i m p E l e m ( r a i z ( a ) ) ; 
 	 	 p r e O r d ( i z q ( a ) ) ; 
 	 	 p r e O r d ( d e r ( a ) ) ; 
 	 } 
 } 
 
 v o i d   p o s T o r D e r ( A r B i n   a ) {   / /   i z q u i e r d o ,   d e r e c h o ,   r a i z 
 	 i f ( ! e s V a c i o ( a ) ) { 
 	 	 p o s T o r D e r ( i z q ( a ) ) ; 
 	 	 p o s T o r D e r ( d e r ( a ) ) ; 
 	 	 i m p E l e m ( r a i z ( a ) ) ; 
 	 } 
 } 
 
 i n t   m a x i m o ( i n t   a ,   i n t   b ) { 
 	 i f ( a > b ) 
 	 	 r e t u r n   a ; 
 	 e l s e 
 	 	 r e t u r n   b ; 
 } 
 
 i n t   a l t u r a A r b o l ( A r B i n   a ) { 
 	 i f ( e s V a c i o ( a ) ) 
 	 	 r e t u r n   0 ; 
 	 e l s e 
 	 	 r e t u r n   1   +   m a x i m o ( a l t u r a A r b o l ( i z q ( a ) ) , a l t u r a A r b o l ( d e r ( a ) ) ) ; 
 } 
 
 i n t   e s H o j a ( A r B i n   a ) { 
 	 r e t u r n   e s V a c i o ( i z q ( a ) ) & & e s V a c i o ( d e r ( a ) ) ; 
 } 
 
 i n t   e s I n t e r n o ( A r B i n   a ) { 
 	 r e t u r n   ( ! e s H o j a ( a ) ) ; 
 } 
 
 i n t   n i v e l ( A r B i n   a ) { 
 	 r e t u r n   a l t u r a A r b o l ( a ) - 1 ; 
 } 
 
 / /   u n   n o d o   q u e   n o   t i e n e   h i j o s   s e   l e   l l a m a   h o j a 
 / /   i n t e r i o r   e s   q u e   n o   e s   u n a   h o j a   
 
 
 / /   a r b o l   c o n   p r i o r i d a d e s 
 
 
 