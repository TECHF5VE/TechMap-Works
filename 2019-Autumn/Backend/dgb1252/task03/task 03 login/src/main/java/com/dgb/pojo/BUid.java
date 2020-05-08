package com.dgb.pojo;

/**
 *
 */
public class BUid {
    /**
     * 用户id
     */
    private Integer uid;
    /**
     * 书id
     */
    private Integer bid;

    @Override
    public String toString() {
        return "BUid{" +
                "uid=" + uid +
                ", bid=" + bid +
                '}';
    }

    public Integer getUid() {
        return uid;
    }

    public void setUid(Integer uid) {
        this.uid = uid;
    }

    public Integer getBid() {
        return bid;
    }

    public void setBid(Integer bid) {
        this.bid = bid;
    }

    public BUid(Integer uid, Integer bid) {
        this.uid = uid;
        this.bid = bid;
    }

    public BUid() {
    }
}
