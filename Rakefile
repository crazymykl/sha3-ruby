require "bundler/gem_tasks"

require 'rake/extensiontask'

GEMSPEC = eval(File.read(File.expand_path("../sha3-ruby.gemspec", __FILE__)))

Rake::ExtensionTask.new('sha3', GEMSPEC)
