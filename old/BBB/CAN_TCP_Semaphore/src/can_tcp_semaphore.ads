package can_tcp_semaphore is

   protected type Semaphore (available : Boolean := true) is
      entry Wait; -- P operation
      procedure Signal; -- V operation
   private
      Value : Boolean := Initial;
   end Semaphore;





end can_tcp_semaphore;
