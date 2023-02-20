package com.xizhe.demo.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

/**
 * @author admin
 * @version 1.0
 * @description: TODO
 * @date 2023/2/20 12:45
 */

@TableName("school")
@Data
public class School implements Serializable {

    @TableId(type = IdType.ASSIGN_ID)
    private Integer id;

    private String name;

}
