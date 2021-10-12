package body can_tcp_semaphore is
   protected body Semaphore is
      entry Wait when Value = true is
      begin
         Value := false;
      end Wait;
      procedure Signal is
      begin
         Value := True;
      end Signal;
   end Semaphore;

end can_tcp_semaphore;
