from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import OVSSwitch, Controller, RemoteController

class RectTopo( Topo ):
    "Rectangular topology example."

    def __init__( self ):
        "Create custom topo."

        # Initialize topology
        Topo.__init__( self )

        # Add hosts and switchesovs-ofctl
        h1 = self.addHost( 'h1' )
        h2 = self.addHost( 'h2' )
        h3 = self.addHost( 'h3' )
        h4 = self.addHost( 'h4' )
        s1 = self.addSwitch( 's1' )
        s2 = self.addSwitch( 's2' )
        s3 = self.addSwitch( 's3' )
        s4 = self.addSwitch( 's4' )

        # Add links
        self.addLink( h1, s1 )
	self.addLink( h2, s2 )
	self.addLink( h3, s3 )
	self.addLink( h4, s4 )

	self.addLink( s1, s2 )
	self.addLink( s2, s3 )
	self.addLink( s3, s4 )
#	self.addLink( s4, s1 )

topos = { 'recttopo': ( lambda: RectTopo() ) }
