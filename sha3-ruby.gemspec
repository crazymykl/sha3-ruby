# -*- encoding: utf-8 -*-
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'sha3-ruby/version'

Gem::Specification.new do |gem|
  gem.name          = "sha3-ruby"
  gem.version       = Sha3::Ruby::VERSION
  gem.authors       = ["Mike MacDonald (crazymykl)"]
  gem.email         = ["crazymykl@gmail.com"]
  gem.description   = %q{Ruby bindings for the (C) reference implementation of SHA-3 cryptographic hash function.}
  gem.summary       = %q{SHA-3, now in Ruby flavor!}
  gem.homepage      = ""

  gem.files         = `git ls-files`.split($/)
  gem.executables   = gem.files.grep(%r{^bin/}).map{ |f| File.basename(f) }
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.require_paths = ["lib"]

  gem.extensions = ['ext/sha3/extconf.rb']
end
