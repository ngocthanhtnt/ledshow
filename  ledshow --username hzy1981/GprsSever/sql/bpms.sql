CREATE TABLE `ct_consume` (
  `consumeid` int(10) unsigned NOT NULL auto_increment,
  `customerid` int(10) unsigned NOT NULL,
  `consumedate` date NOT NULL,
  `consumeprice` decimal(10,2) NOT NULL default '0.00',
  `remark` varchar(255) default NULL,
  PRIMARY KEY  (`consumeid`),
  KEY `ct_consume_FKIndex1` (`customerid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `ct_consumedetail` (
  `consumeid` int(10) unsigned NOT NULL,
  `goodsid` int(10) unsigned NOT NULL,
  `goodsnum` int(10) unsigned NOT NULL default '0',
  `goodsprice` decimal(10,2) NOT NULL default '0.00',
  `remark` varchar(255) default NULL,
  PRIMARY KEY  (`consumeid`,`goodsid`),
  KEY `ct_consume_has_ct_goods_FKIndex1` (`consumeid`),
  KEY `ct_consume_has_ct_goods_FKIndex2` (`goodsid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


CREATE TABLE `ct_customer` (
  `customerid` int(10) unsigned NOT NULL auto_increment,
  `customerno` char(32) NOT NULL,
  `fullname` char(32) NOT NULL,
  `employ` char(32) default NULL,
  `consumeprice` decimal(10,2) NOT NULL default '0.00',
  `gender` tinyint(3) unsigned NOT NULL default '0',
  `birth` date default NULL,
  `adddate` date NOT NULL,
  `phone` char(32) default NULL,
  `mobile` char(32) default NULL,
  `company` varchar(255) default NULL,
  `address` varchar(255) default NULL,
  `remark` varchar(255) default NULL,
  PRIMARY KEY  (`customerid`),
  KEY `ct_customer_index1061` (`customerno`),
  KEY `ct_customer_index1062` (`fullname`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `ct_goods` (
  `goodsid` int(10) unsigned NOT NULL auto_increment,
  `goodsno` char(32) NOT NULL,
  `goodsname` char(32) NOT NULL,
  `sellprice` decimal(10,2) NOT NULL default '0.00',
  `inprice` decimal(10,2) NOT NULL default '0.00',
  `goodsnum` int(10) unsigned NOT NULL default '0',
  `isservices` tinyint(3) unsigned NOT NULL default '0',
  `manufacturer` varchar(63) default NULL,
  PRIMARY KEY  (`goodsid`),
  KEY `ct_goods_index1074` (`goodsno`),
  KEY `ct_goods_index1075` (`sellprice`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
