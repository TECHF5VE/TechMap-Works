package com.dgb.dao;

import com.dgb.pojo.BUid;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.Map;

@Repository
@Mapper
public interface BUMapper {
    /**
     *description: 查询某一本书是否在用户的喜爱中
     * @param map
     * @return
     */
    BUid query(Map<String,Integer> map);
}
