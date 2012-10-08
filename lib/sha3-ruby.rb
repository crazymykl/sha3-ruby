require "sha3"
require "sha3-ruby/version"

module Sha3
  class Instance
        
    def update str
      __update str
    end
    
    def digest
      __final
    end
    
    alias :'<<' :update 

  end
    
  def self.new bits=224
    Instance.__init(bits)
  end
  
  def self.digest str, bits=224
    __hash(str, bits)
  end

end
